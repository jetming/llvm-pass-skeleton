PROJECT(func_update)
CMAKE_MINIMUM_REQUIRED(VERSION 3.4.3)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "LLVM_DEFINITIONS = ${LLVM_DEFINITIONS}")
message(STATUS "LLVM_INCLUDE_DIRS = ${LLVM_INCLUDE_DIRS}")
message(STATUS "LLVM_LIBRARY_DIRS = ${LLVM_LIBRARY_DIRS}")

add_definitions(${LLVM_DEFINITIONS})
add_definitions(-fPIC -Wall -std=c++11 -g -fno-exceptions -fno-rtti)

include_directories(
    ${LLVM_INCLUDE_DIRS}
	${PROJECT_SOURCE_DIR}/include
)

link_directories(
    ${LLVM_LIBRARY_DIRS}
	${PROJECT_SOURCE_DIR}/lib
)

llvm_map_components_to_libnames(llvm_libs irreader codegen BitReader Linker BitWriter Core ScalarOpts Support SelectionDAG AsmPrinter TransformUtils) 

message(STATUS "llvm_libs = ${llvm_libs}")

add_subdirectory(src)
AUX_SOURCE_DIRECTORY(. DIR_EXE_SRC)
ADD_EXECUTABLE(pass_exe ${DIR_EXE_SRC})
TARGET_LINK_LIBRARIES( pass_exe obfus utils ${llvm_libs})
set(EXECUTABLE_OUTPUT_PATH ../test)
