#ifndef O3LIB_NONCOPYABLE_H
#define O3LIB_NONCOPYABLE_H
#include "detail/common.h"

namespace o3 {
    class noncopyable {
    public:
        typedef noncopyable this_type;
    protected:
        noncopyable() { }
        ~noncopyable() { }
    private:
        noncopyable(this_type const &);
        this_type &operator=(this_type const &);
    }; // END of clas noncopyable
} // END of namespace o3

#endif //O3LIB_NONCOPYABLE_H
