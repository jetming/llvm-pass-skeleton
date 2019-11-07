/*
 * @Description: get functions of the given module 
 * @Author: jetming
 * @Date: 2019-11-07 10:45:14
 * @LastEditTime: 2019-11-07 14:27:22
 * @LastEditors: puzhiming
 */

#include "Passes.h"
#include "log.h"

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

ModulePass *llvm::createGetFuncPass() {
  return new GetFunc();
}