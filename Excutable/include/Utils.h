#ifndef __UTILS_OBF__
#define __UTILS_OBF__

#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Transforms/Utils/Local.h" // For DemoteRegToStack and DemotePHIToStack
#include <stdio.h>
#include <sstream>
#include <map>
#include <set>
using namespace std;
using namespace llvm;

namespace obf {
    std::string readAnnotate(Function *f);
    void writeTxtBitcode(StringRef path, Module &M);
}
#endif
