cmake_minimum_required(VERSION 3.13)
project(clang_instrument LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(LLVM_DIR "" CACHE PATH "Path to LLVM CMake configuration")
set(Clang_DIR "" CACHE PATH "Path to Clang CMake configuration")
set(LLVM_LIB_DIR "" CACHE PATH "Path to LLVM libraries directory")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

if(NOT LLVM_LIB_DIR)
    message(FATAL_ERROR "LLVM_DIR must be specified. Use -DLLVM_LIB_DIR=/path/to/llvm/build/lib")
endif()

if(NOT LLVM_DIR)
    set(LLVM_DIR "${LLVM_LIB_DIR}/cmake/llvm" CACHE PATH "" FORCE)
endif()

if(NOT Clang_DIR)
    set(Clang_DIR "${LLVM_LIB_DIR}/cmake/clang" CACHE PATH "" FORCE)
endif()


find_package(LLVM REQUIRED CONFIG)
include(AddLLVM)
find_package(Clang CONFIG) 

llvm_map_components_to_libnames(llvm_libs
    support
    core
    option
    frontendopenmp
    ipo
    transformutils
    scalaropts
)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})


# ========== loop extractor ==========
add_executable(loopExtractor LoopExtractor.cpp)

target_link_libraries(loopExtractor
  PRIVATE
    clangTooling
    clangToolingCore
    clangFrontend
    clangFrontendTool
    clangAST
    clangASTMatchers
    clangBasic
    clangLex
    clangSerialization
    clangRewrite
    LLVMCore
    LLVMSupport
    ${llvm_libs}
)

target_compile_options(loopExtractor PRIVATE -frtti)

# ========== AST feature extractor ==========
add_executable(getASTFeature ASTFeatureExtractor.cpp)

target_link_libraries(getASTFeature
  PRIVATE
    clangTooling
    clangToolingCore
    clangFrontend
    clangFrontendTool
    clangAST
    clangASTMatchers
    clangBasic
    clangLex
    clangSerialization
    clangRewrite
    LLVMCore
    LLVMSupport
    LLVMFrontendOpenMP 
    ${llvm_libs}
)

# ========== IR feature extractor ==========
add_library(IRLoopFeatureExtractor MODULE IRFeatureExtractor.cpp)

set_target_properties(IRLoopFeatureExtractor PROPERTIES
    COMPILE_FLAGS "-fno-rtti"
)

llvm_map_components_to_libnames(llvm_libs support core passes analysis)

target_include_directories(IRLoopFeatureExtractor PRIVATE ${LLVM_INCLUDE_DIRS})
