#ifndef O3LIB_EXCEPT_H
#define O3LIB_EXCEPT_H
#include "detail/common.h"
#include "macros.h"
#include <exception>
#include <stdexcept>
#include <string>

#define O3_DECLARE_EXCEPTION_TYPE(identifier, base_class) \
    class identifier \
        : public base_class { \
    public: \
        typedef identifier this_type; \
        typedef base_class base_type; \
        \
        explicit identifier(std::string const &what_arg) \
            : base_type(what_arg) { } \
        explicit identifier(char const *what_arg) \
            : base_type(what_arg) { } \
        \
        virtual char const *what() const O3_NOEXCEPT { \
            return base_type::what(); \
        } \
    }

namespace o3 {
    O3_DECLARE_EXCEPTION_TYPE(nullpointer_exception, std::logic_error);
    O3_DECLARE_EXCEPTION_TYPE(assertion_violation, std::runtime_error);
    O3_DECLARE_EXCEPTION_TYPE(precondition_violation, assertion_violation);
    O3_DECLARE_EXCEPTION_TYPE(postcondition_violation, assertion_violation);
    O3_DECLARE_EXCEPTION_TYPE(bad_index, std::out_of_range);
} // END of namespace o3

#endif //O3LIB_EXCEPT_H
