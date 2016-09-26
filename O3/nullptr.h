#ifndef O3LIB_NULLPTR_H
#define O3LIB_NULLPTR_H

#include "detail/common.h"
#include <cstddef>

namespace o3 {
    class nullptr_t {
    public:
        typedef nullptr_t this_type;
        
        template <typename Ty>
        operator Ty *() const {
            return 0;
        }
        
        template <typename Class, typename Ty>
        operator Ty Class:: *() const {
            return 0;
        }
        
        operator void *() const {
            return 0;
        }
        
        friend bool operator==(this_type const &,
                               this_type const &) {
            return true;
        }
        
        friend bool operator!=(this_type const &,
                               this_type const &) {
            return false;
        }
        
    private:
        void volatile *padding_;
    }; // END of class nullptr_t
} // END of namespace o3

#define O3_NULLPTR  ((o3::nullptr_t()))

#endif //O3LIB_NULLPTR_H
