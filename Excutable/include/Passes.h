/*************************************************************************
	> File Name: passes.h
	> Author: jetming
	> Created Time: Mon 25 Mar 2019 04:19:22 AM PDT
    > Description: description
 ************************************************************************/
#ifndef _PASSES_H
#define _PASSES_H
#include "llvm/Pass.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/PassRegistry.h"

namespace llvm
{
	ModulePass *createGetFuncPass();
} // namespace exe

#endif

