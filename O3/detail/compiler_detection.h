#ifndef O3LIB_COMPILER_DETECTION_H
#define O3LIB_COMPILER_DETECTION_H

#define O3_COMPILER_CLANG   1
#define O3_COMPILER_MSVC    2
#define O3_COMPILER_GCC     3

#if defined(__clang__)
#   define O3_COMPILER      O3_COMPILER_CLANG
#elif defined(_MSC_VER)
#   define O3_COMPILER      O3_COMPILER_MSVC
#elif defined(__GNUC__)
#   define O3_COMPILER      O3_COMPILER_GCC
#else
#   error "The compiler being used is not supported by O3Lib"
#endif

#endif //O3LIB_COMPILER_DETECTION_H
