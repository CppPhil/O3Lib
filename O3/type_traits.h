#ifndef O3LIB_TYPE_TRAITS_H
#define O3LIB_TYPE_TRAITS_H

#include "detail/common.h"
#include "macros.h"
#include <cstddef>

namespace o3 {
    template <class Ty, Ty v>
    struct integral_constant {
        static const Ty value = v;
        
        typedef Ty value_type;
        typedef integral_constant type;
        
        operator value_type() const O3_NOEXCEPT {
            return value;
        }
        
        value_type operator()() const O3_NOEXCEPT {
            return value;
        }
    };
    
    typedef integral_constant<bool, true> true_type;
    typedef integral_constant<bool, false> false_type;
        
    template <class Ty>
    struct add_const {
        typedef const Ty type;
    };
    
    template <class Ty>
    struct add_volatile {
        typedef volatile Ty type;
    };
    
    template <class Ty>
    struct add_cv {
        typedef const volatile Ty type;
    };
    
    template <class Ty>
    struct remove_const {
        typedef Ty type;
    };
    
    template <class Ty>
    struct remove_const<const Ty> {
        typedef Ty type;
    };
    
    template <class Ty>
    struct remove_volatile {
        typedef Ty type;
    };
    
    template <class Ty>
    struct remove_volatile<volatile Ty> {
        typedef Ty type;
    };
    
    template <class Ty>
    struct remove_cv {
        typedef typename remove_volatile<typename remove_const<Ty>::type>::type type;
    };
    
    template <class Ty>
    struct remove_extent {
        typedef Ty type;
    };
    
    template <class Ty, std::size_t Ix>
    struct remove_extent<Ty[Ix]> {
        typedef Ty type;
    };
    
    template <class Ty>
    struct remove_extent<Ty[]> {
        typedef Ty type;
    };
    
    template <class Ty>
    struct remove_all_extents {
        typedef Ty type;
    };
    
    template <class Ty, std::size_t Ix>
    struct remove_all_extents<Ty[Ix]> {
        typedef typename remove_all_extents<Ty>::type type;
    };

    template <class Ty>
    struct remove_all_extents<Ty[]> {
        typedef typename remove_all_extents<Ty>::type type;
    };
    
    template <class Ty>
    struct remove_pointer {
        typedef Ty type;
    };
    
    template <class Ty1, class Ty2>
    struct is_same : false_type { };
    
    template <class Ty1>
    struct is_same<Ty1, Ty1> : true_type { };
    
    template <class Ty>
    struct is_array : false_type { };
    
    template <class Ty, std::size_t Nx>
    struct is_array<Ty[Nx]> : true_type { };
    
    template <class Ty>
    struct is_lvalue_reference : false_type { };
    
    template <class Ty>
    struct is_lvalue_reference<Ty &> : true_type { };
    
    template <class Ty>
    struct is_reference : is_lvalue_reference<Ty> { };
    
    template <class Ty>
    struct is_const : false_type { };
    
    template <class Ty>
    struct is_const<const Ty> : true_type { };
    
    template <class Ty>
    struct is_volatile : false_type { };
    
    template <class Ty>
    struct is_volatile<volatile Ty> : true_type { };
    
    template <class Ty>
    struct is_void : is_same<void, typename remove_cv<Ty>::type> { };
    
    template <class Ty>
    struct is_floating_point
        : integral_constant<bool,
                is_same<float, typename remove_cv<Ty>::type>::value ||
                is_same<double, typename remove_cv<Ty>::type>::value> { };
    
    namespace detail {
        template <class Ty>
        struct is_pointer_helper : false_type { };
        
        template <class Ty>
        struct is_pointer_helper<Ty *> : true_type { };
    } // END of namespace detail
   
    template <class Ty>
    struct is_pointer : detail::is_pointer_helper<typename remove_cv<Ty>::type> { };
    
    template <class Ty>
    struct rank : integral_constant<std::size_t, 0> { };
    
    template <class Ty, std::size_t Ix>
    struct rank<Ty[Ix]> : integral_constant<std::size_t, rank<Ty>::value + 1> { };
    
    template <class Ty>
    struct rank<Ty[]> : integral_constant<std::size_t, rank<Ty>::value +1 > { };
    
    template <bool Bool, class Ty = void>
    struct enable_if { };
    
    template <class Ty>
    struct enable_if<true, Ty> {
        typedef Ty type;
    };
    
    template <bool Bool, class True, class False>
    struct conditional {
        typedef True type;
    };
    
    template <class True, class False>
    struct conditional<false, True, False> {
        typedef False type;
    };
    
    template <class Ty>
    struct identity {
        typedef Ty type;
    };
} // END of namespace o3

#endif //O3LIB_TYPE_TRAITS_H
