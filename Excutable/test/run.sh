#!/bin/bash
set -e

export PATH=$(your own llvm installed path)/bin:$PATH

mkdir -p ../build
cd ../build
clang --version
CC=clang CXX=clang++ cmake ../ -G Ninja -DCMAKE_BUILD_TYPE:STRING=Debug
ninja
cd ../test 

clang -emit-llvm -S for_while.c
./pass_exe for_while.ll for_while.out.ll
clang for_while.out.ll
./a.out
