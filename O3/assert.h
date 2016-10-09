#ifndef O3LIB_ASSERT_H
#define O3LIB_ASSERT_H
#include "detail/common.h"
#include "except.h"
#include "macros.h"

#define O3_ASSERT(cond) O3_DETAIL_BEGIN_MACRO \
    if (!(cond)) { \
        throw o3::assertion_violation("O3: Assertion violation at " __FILE__ ": " O3_STRINGIFY(__LINE__)); \
    } O3_DETAIL_END_MACRO

#define O3_CHECK_PRE(cond) O3_DETAIL_BEGIN_MACRO \
    if (!(cond)) { \
        throw o3::precondition_violation("O3: Precondition violation at " __FILE__ ": " O3_STRINGIFY(__LINE__)); \
    } O3_DETAIL_END_MACRO

#define O3_CHECK_POST(cond) O3_DETAIL_BEGIN_MACRO \
    if (!(cond)) { \
        throw o3::postcondition_violation("O3: Postcondition violation at " __FILE__ ": " O3_STRINGIFY(__LINE__)); \
    } O3_DETAIL_END_MACRO

#endif //O3LIB_ASSERT_H
