#ifndef O3LIB_EXCEPT_H
#define O3LIB_EXCEPT_H

#include "detail/common.h"
#include "macros.h"
#include <exception>
#include <stdexcept>
#include <string>

namespace o3 {
    class nullpointer_exception
            : public std::logic_error {
    public:
        typedef nullpointer_exception this_type;
        typedef std::logic_error base_type;
        
        explicit nullpointer_exception(std::string const &what_arg)
            : base_type(what_arg) { }
        
        explicit nullpointer_exception(char const *what_arg)
            : base_type(what_arg) { }

        virtual char const *what() const O3_NOEXCEPT {
            return base_type::what();
        }
    }; // END of class nullpointer_exeption
} // END of namespace o3

#endif //O3LIB_EXCEPT_H
