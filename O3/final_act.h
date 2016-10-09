#ifndef O3LIB_FINAL_ACT_H
#define O3LIB_FINAL_ACT_H
#include "detail/common.h"
#include "macros.h"

namespace o3 {
    template <typename Callable>
    class final_act {
    public:
        typedef final_act this_type;
        typedef Callable element_type;
        
        explicit final_act(element_type callable) O3_NOEXCEPT
            : callable_(callable) { }
        
        ~final_act() O3_NOEXCEPT {
            callable_();
        }
        
    private:
        final_act(this_type const &);
        this_type &operator=(this_type const &);
        
        element_type callable_;
    };
} // END of namespace o3

#endif //O3LIB_FINAL_ACT_H
