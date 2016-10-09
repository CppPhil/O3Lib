#ifndef O3LIB_MACROS_H
#define O3LIB_MACROS_H
#include "detail/common.h"

#if O3_COMPILER == O3_COMPILER_CLANG
#    define O3_FORCE_INLINE      __attribute__((always_inline))
#    define O3_SUGGEST_INLINE    inline
#    define O3_PROHIBIT_INLINE   __attribute__((noinline))
#    define O3_RESTRICT          __restrict__
#    if __has_feature(cxx_noexcept)
#        define O3_HAS_NOEXCEPT  1
#    else
#        define O3_HAS_NOEXCEPT  0
#    endif
#elif O3_COMPILER == O3_COMPILER_MSVC
#    define O3_FORCE_INLINE      __forceinline
#    define O3_SUGGEST_INLINE    inline
#    define O3_PROHIBIT_INLINE   __declspec(noinline)
#    define O3_RESTRICT          __restrict
#    if _MSC_FULL_VER >= 190023026
#        define O3_HAS_NOEXCEPT  1
#    else
#        define O3_HAS_NOEXCEPT  0
#    endif
#elif O3_COMPILER == O3_COMPILER_GCC
#    define O3_FORCE_INLINE      __attribute__((always_inline)) inline
#    define O3_SUGGEST_INLINE    inline
#    define O3_PROHIBIT_INLINE   __attribute__((noinline))
#    define O3_RESTRICT          __restrict__
#    if __GNUC__ * 10 + __GNUC_MINOR__ >= 46
#        define O3_HAS_NOEXCEPT  1
#    else
#        define O3_HAS_NOEXCEPT  0
#    endif
#endif

#if O3_HAS_NOEXCEPT
#    define O3_NOEXCEPT          noexcept
#else
#    define O3_NOEXCEPT          throw()
#endif

#undef O3_HAS_NOEXCEPT

#define O3_DETAIL_BEGIN_MACRO    do {
#define O3_DETAIL_END_MACRO      } while (false)

#define O3_UNUSED(param)         (static_cast<void>((param)))
#define O3_MAX(a, b)             (((a) > (b)) ? (a) : (b))
#define O3_MIN(a, b)             (((a) < (b)) ? (a) : (b))
#define O3_DETAIL_STRINGIFY(x)   #x
#define O3_STRINGIFY(x)          O3_DETAIL_STRINGIFY(x)
#define O3_DETAIL_GLUE(a, b)     a##b
#define O3_GLUE(a, b)            O3_DETAIL_GLUE(a, b)
#define O3_SELF                  (*this)
#define O3_IN
#define O3_OUT
#define O3_INOUT
#define O3_IN_OPT
#define O3_OUT_OPT
#define O3_INOUT_OPT
#define O3_RET_NOTNULL
#define O3_CHECKRETURN

#endif //O3LIB_MACROS_H
