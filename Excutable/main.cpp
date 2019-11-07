/*************************************************************************
	> File Name: main.cpp
	> Author: jetming
	> Mail: 
	> Created Time: Mon 25 Mar 2019 02:41:13 AM PDT
	> Description: description
 ************************************************************************/
#include "log.h"
#include "Passes.h"
#include "Utils.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Support/ToolOutputFile.h"
#include "llvm/Bitcode/BitcodeWriterPass.h"
#include "llvm/Support/FileSystem.h"
using namespace llvm;

void init()
{
	PassRegistry *Registry = PassRegistry::getPassRegistry();
	initializeCore(*Registry);
	initializeCodeGen(*Registry);
	initializeLoopStrengthReducePass(*Registry);
	initializeLowerIntrinsicsPass(*Registry);
	initializeCountingFunctionInserterPass(*Registry);
	initializeUnreachableBlockElimLegacyPassPass(*Registry);
}

int runPasses(std::string &mod_name, std::string &out, std::vector<Pass*> &passes)
{
	SMDiagnostic Err;
	LLVMContext Context;
	std::unique_ptr<Module> theOrginal = parseIRFile(mod_name, Err, Context);
	if (!theOrginal) {
		LOGE("theOrginal is null");
		return 1;
	}

	std::unique_ptr<tool_output_file> Out;
	std::error_code EC;
	Out.reset(new tool_output_file(out, EC, sys::fs::F_None));
	if (EC) {
		LOGE("%s", EC.message().data());
		return 1;
	}

	legacy::PassManager pm;
	for (auto pass : passes) {
		LOGD("add pass: %s", pass->getPassName().data());
		pm.add(pass);
	}
	//pm.add(llvm::createBitcodeWriterPass(Out->os(), true, false, false));
	pm.run(*theOrginal);
	Out->keep();

	obf::writeTxtBitcode(out, *theOrginal);
	return 0;
}

int main(int argc, char* argv[])
{
	if (argc != 3) {
		LOGE("error args! need src module and out moudle, eg: ./main src.ll out.ll");
		return 1;
	}
	init();

	std::string src(argv[1]);
	std::string out(argv[2]);
	int ret;
	std::vector<Pass*>passes;
	passes.clear();
	passes.push_back(createGetFuncPass());
		
	LOGD("number of pass: %d", passes.size());
	runPasses(src, out, passes);
	return 0;
}