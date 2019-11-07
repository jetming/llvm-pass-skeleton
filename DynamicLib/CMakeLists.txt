cmake_minimum_required(VERSION 3.1)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "${CMAKE_MODULE_PATH} ${CMAKE_ROOT}")
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "LLVM_DEFINITIONS = ${LLVM_DEFINITIONS}")
message(STATUS "LLVM_INCLUDE_DIRS = ${LLVM_INCLUDE_DIRS}")
message(STATUS "LLVM_LIBRARY_DIRS = ${LLVM_LIBRARY_DIRS}")

add_definitions(${LLVM_DEFINITIONS})
include_directories(
	${LLVM_INCLUDE_DIRS}
	${PROJECT_SOURCE_DIR}/include
)
link_directories(${LLVM_LIBRARY_DIRS})

add_subdirectory(getFunc)