/*************************************************************************
	> File Name: log.h
	> Author: jetming
	> Mail: puzhiming@migu.cn
	> Created Time: Sun 12 May 2019 08:21:44 PM PDT
    > Description: description
 ************************************************************************/
#ifndef _LOG_H
#define _LOG_H

#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/ToolOutputFile.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/IR/AssemblyAnnotationWriter.h"

#define  LOGD(format, ...)  DEBUG(printf("[DEBUG]" __FILE__", %d: " format"\n", __LINE__, ##__VA_ARGS__))
#define	 LOGE(format, ...)	printf("[ERROR]" __FILE__", %d: " format"\n", __LINE__, ##__VA_ARGS__)

using namespace llvm;

void writeTxtBitcode(StringRef path, Module &M) {
	std::error_code EC;
	std::unique_ptr<tool_output_file> Out(new tool_output_file(path, EC, sys::fs::F_None));
	if (EC) {
		LOGE("file create error! %s", path.data());
		return;
	}
	std::unique_ptr<AssemblyAnnotationWriter> Annotator;
	M.print(Out->os(), Annotator.get());

	Out->keep();
}
#endif

