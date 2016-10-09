#ifndef O3LIB_FUNCTIONAL_H
#define O3LIB_FUNCTIONAL_H
#include "detail/common.h"
#include <functional>

namespace o3 {
    template <typename Ty>
    struct bit_and {
        Ty operator()(Ty const &a, Ty const &b) const {
            return a & b;
        }
    };
    
    template <typename Ty>
    struct bit_or {
        Ty operator()(Ty const &a, Ty const &b) const {
            return a | b;
        }
    };
    
    template <typename Ty>
    struct bit_xor {
        Ty operator()(Ty const &a, Ty const &b) const {
            return a ^ b;
        }
    };
} // END of namespace o3

#endif //O3LIB_FUNCTIONAL_H
