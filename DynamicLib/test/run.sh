#!/bin/bash
set -e
export PATH=$(your own llvm installed path)/bin:$PATH

mkdir -p ../build
cd ../build
clang --version
CC=clang CXX=clang++ cmake ../ -G Ninja -DCMAKE_BUILD_TYPE:STRING=Debug
ninja
cd ../test
opt --version

clang -emit-llvm -S for_while.c

opt -load ../build/getFunc/libGetFunc.so -GetFunc for_while.ll
