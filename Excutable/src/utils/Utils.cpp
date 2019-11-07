#include "Utils.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/NoFolder.h"
#include "llvm/Support/ToolOutputFile.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/IR/AssemblyAnnotationWriter.h"

std::string obf::readAnnotate(Function *f) {
  std::string annotation = "";

  // Get annotation variable
  GlobalVariable *glob =
      f->getParent()->getGlobalVariable("llvm.global.annotations");

  if (glob != NULL) {
    // Get the array
    if (ConstantArray *ca = dyn_cast<ConstantArray>(glob->getInitializer())) {
      for (unsigned i = 0; i < ca->getNumOperands(); ++i) {
        // Get the struct
        if (ConstantStruct *structAn =
                dyn_cast<ConstantStruct>(ca->getOperand(i))) {
          if (ConstantExpr *expr =
                  dyn_cast<ConstantExpr>(structAn->getOperand(0))) {
            // If it's a bitcast we can check if the annotation is concerning
            // the current function
            if (expr->getOpcode() == Instruction::BitCast &&
                expr->getOperand(0) == f) {
              ConstantExpr *note = cast<ConstantExpr>(structAn->getOperand(1));
              // If it's a GetElementPtr, that means we found the variable
              // containing the annotations
              if (note->getOpcode() == Instruction::GetElementPtr) {
                if (GlobalVariable *annoteStr =
                        dyn_cast<GlobalVariable>(note->getOperand(0))) {
                  if (ConstantDataSequential *data =
                          dyn_cast<ConstantDataSequential>(
                              annoteStr->getInitializer())) {
                    if (data->isString()) {
                      annotation += data->getAsString().lower() + " ";
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return annotation;
}

void obf::writeTxtBitcode(StringRef path, Module &M) {
	std::error_code EC;
	std::unique_ptr<tool_output_file> Out(new tool_output_file(path, EC, sys::fs::F_None));
	if (EC) {
		return;
	}
	std::unique_ptr<AssemblyAnnotationWriter> Annotator;
	M.print(Out->os(), Annotator.get());

	Out->keep();
}