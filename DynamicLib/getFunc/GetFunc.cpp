/*
 * @Description: get functions of the given module 
 * @Author: puzhiming
 * @Date: 2019-11-07 10:45:14
 * @LastEditTime: 2019-11-07 11:18:39
 * @LastEditors: puzhiming
 */

#include "llvm/Pass.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/PassRegistry.h"

#include "log.h"

#define DEBUG_TYPE "GetFunc"
using namespace llvm;

class GetFunc : public ModulePass
{
private:
    /* data */
public:
    static char ID;

    GetFunc() :ModulePass(ID) {}

    bool runOnModule(Module &m);
};

char GetFunc::ID = 0;
static RegisterPass<GetFunc> X("GetFunc", "GetFunc", true, true);

bool GetFunc::runOnModule(Module &m)
{
    for (auto ite = m.begin(); ite != m.end(); ite++)
    {
        if (ite->hasName())
        {
            LOGD("find func: %s", ite->getName().data());
        }
        
    }
    
	return false;
}