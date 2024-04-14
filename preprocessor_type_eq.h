/*
 *	CREATED BY SHPEGUN60
 *
 *  TYPE DETECT MACROCES
 */

#ifndef __PREPROCESSOR_TYPE_EQ_H__
#define __PREPROCESSOR_TYPE_EQ_H__ 1


/*********************************************************************************************************************
 * C/C++ type detector macro
 *
 *      PREPROCESSOR_TYPE_EQ(int, int)       // expands to 1
 *      PREPROCESSOR_TYPE_EQ(float, int)   // expands to 0
 *      PREPROCESSOR_TYPE_DETECT(int)        // expands to 1
 */
//#define PREPROCESSOR_TYPE_EQ(x, y)           PREPROCESSOR_IS_TUPLE_FAST(PREPROCESSOR_C_TYPE_DETECTOR_##x##_##y)
//#define PREPROCESSOR_TYPE_DETECT(x)          PREPROCESSOR_IS_TUPLE_FAST(PREPROCESSOR_C_TYPE_DETECTOR_##x##_##x)

#define PREPROCESSOR_TYPE_EQ(x, y)           PREPROCESSOR_TYPE_EQ_IMPL(x, y)
#define PREPROCESSOR_TYPE_DETECT(x)          PREPROCESSOR_TYPE_EQ_IMPL(x, x)
#define PREPROCESSOR_TYPE_EQ_IMPL(x, y)      PREPROCESSOR_IS_TUPLE_FAST(PREPROCESSOR_C_TYPE_DETECTOR_##x##_##y)

// standard data types (literals without space)
#define PREPROCESSOR_C_TYPE_DETECTOR_void_void                   ()
#define PREPROCESSOR_C_TYPE_DETECTOR_chat_char                   ()
#define PREPROCESSOR_C_TYPE_DETECTOR_short_short                 ()
#define PREPROCESSOR_C_TYPE_DETECTOR_int_int                     ()
#define PREPROCESSOR_C_TYPE_DETECTOR_signed_signed               ()
#define PREPROCESSOR_C_TYPE_DETECTOR_unsigned_unsigned           ()
#define PREPROCESSOR_C_TYPE_DETECTOR_long_long                   ()
#define PREPROCESSOR_C_TYPE_DETECTOR_float_float                 ()
#define PREPROCESSOR_C_TYPE_DETECTOR_double_double               ()

/*
 * ***********************************************************************************
 * stdint.h types
 * ***********************************************************************************
 */

/*
 * int8_t
 * int16_t
 * int32_t
 * int64_t
 *
 * signed integer type with width of exactly 8, 16, 32 and 64 bits respectively
 * with no padding bits and using 2's complement for negative values
 * (provided if and only if the implementation directly supports the type)
 * (typedef)
 */
#define PREPROCESSOR_C_TYPE_DETECTOR_int8_t_int8_t                   ()
#define PREPROCESSOR_C_TYPE_DETECTOR_int16_t_int16_t                 ()
#define PREPROCESSOR_C_TYPE_DETECTOR_int32_t_int32_t                 ()
#define PREPROCESSOR_C_TYPE_DETECTOR_int64_t_int64_t                 ()


/*
 * int_fast8_t
 * int_fast16_t
 * int_fast32_t
 * int_fast64_t
 *
 * fastest signed integer type with width of at least 8, 16, 32 and 64 bits respectively
 * (typedef)
 */
#define PREPROCESSOR_C_TYPE_DETECTOR_int_fast8_t_int_fast8_t                  ()
#define PREPROCESSOR_C_TYPE_DETECTOR_int_fast16_t_int_fast16_t                ()
#define PREPROCESSOR_C_TYPE_DETECTOR_int_fast32_t_int_fast32_t                ()
#define PREPROCESSOR_C_TYPE_DETECTOR_int_fast64_t_int_fast64_t                ()

/*
 * int_least8_t
 * int_least16_t
 * int_least32_t
 * int_least64_t
 *
 * smallest signed integer type with width of at least 8, 16, 32 and 64 bits respectively
 * (typedef)
 */
#define PREPROCESSOR_C_TYPE_DETECTOR_int_least8_t_int_least8_t                  ()
#define PREPROCESSOR_C_TYPE_DETECTOR_int_least16_t_int_least16_t                ()
#define PREPROCESSOR_C_TYPE_DETECTOR_int_least32_t_int_least32_t                ()
#define PREPROCESSOR_C_TYPE_DETECTOR_int_least64_t_int_least64_t                ()

/*
 * intmax_t
 *
 * maximum-width signed integer type
 * (typedef)
 */
#define PREPROCESSOR_C_TYPE_DETECTOR_intmax_t_intmax_t                  ()

/*
 * intptr_t
 *
 * (optional)
 *
 * signed integer type capable of holding a pointer to void
 * (typedef)
 */
#define PREPROCESSOR_C_TYPE_DETECTOR_intptr_t_intptr_t                  ()

/*
 * uint8_t
 * uint16_t
 * uint32_t
 * uint64_t
 *
 * (optional)
 *
 * unsigned integer type with width of exactly 8, 16, 32 and 64 bits respectively
 * (provided if and only if the implementation directly supports the type)
 * (typedef)
 */
#define PREPROCESSOR_C_TYPE_DETECTOR_uint8_t_uint8_t                  ()
#define PREPROCESSOR_C_TYPE_DETECTOR_uint16_t_uint16_t                ()
#define PREPROCESSOR_C_TYPE_DETECTOR_uint32_t_uint32_t                ()
#define PREPROCESSOR_C_TYPE_DETECTOR_uint64_t_uint64_t                ()

/*
 * uint_fast8_t
 * uint_fast16_t
 * uint_fast32_t
 * uint_fast64_t
 *
 * fastest unsigned integer type with width of at least 8, 16, 32 and 64 bits respectively
 * (typedef)
 */
#define PREPROCESSOR_C_TYPE_DETECTOR_uint_fast8_t_uint_fast8_t                  ()
#define PREPROCESSOR_C_TYPE_DETECTOR_uint_fast16_t_uint_fast16_t                ()
#define PREPROCESSOR_C_TYPE_DETECTOR_uint_fast32_t_uint_fast32_t                ()
#define PREPROCESSOR_C_TYPE_DETECTOR_uint_fast64_t_uint_fast64_t                ()

/*
 * uint_least8_t
 * uint_least16_t
 * uint_least32_t
 * uint_least64_t
 *
 * smallest unsigned integer type with width of at least 8, 16, 32 and 64 bits respectively
 * (typedef)
 */
#define PREPROCESSOR_C_TYPE_DETECTOR_uint_least8_t_uint_least8_t                  ()
#define PREPROCESSOR_C_TYPE_DETECTOR_uint_least16_t_uint_least16_t                ()
#define PREPROCESSOR_C_TYPE_DETECTOR_uint_least32_t_uint_least32_t                ()
#define PREPROCESSOR_C_TYPE_DETECTOR_uint_least64_t_uint_least64_t                ()

/*
 * uintmax_t
 *
 * maximum-width unsigned integer type
 * (typedef)
 */
#define PREPROCESSOR_C_TYPE_DETECTOR_uintmax_t_uintmax_t                  ()

 /*
  * uintptr_t
  *
  * (optional)
  *
  * unsigned integer type capable of holding a pointer to void
  * (typedef)
  */
 #define PREPROCESSOR_C_TYPE_DETECTOR_uintptr_t_uintptr_t                  ()

/*
 * ***********************************************************************************
 * stddef.h types
 * ***********************************************************************************
 */

/*
 * ptrdiff_t       Result of pointer subtraction (type)
 * size_t          Unsigned integral type (type)
 * max_align_t     Type with widest scalar alignment (type)
 * nullptr_t       Null pointer type (C++) (type)
 * wchar_t         universal char type
 */
#define PREPROCESSOR_C_TYPE_DETECTOR_ptrdiff_t_ptrdiff_t            ()
#define PREPROCESSOR_C_TYPE_DETECTOR_size_t_size_t                  ()
#define PREPROCESSOR_C_TYPE_DETECTOR_max_align_t_max_align_t        ()
#define PREPROCESSOR_C_TYPE_DETECTOR_nullptr_t_nullptr_t            ()
#define PREPROCESSOR_C_TYPE_DETECTOR_wchar_t_wchar_t                ()

/*
 * ***********************************************************************************
 * other user types
 * ***********************************************************************************
 */

/*
 * typedef void            uni; // do not check this type because void type is not exist, error type
 * typedef uint8_t         u8;
 * typedef uint16_t        u16;
 * typedef uint32_t        u24;
 * typedef uint32_t        u32;
 * typedef uint64_t        u64;
 *
 * typedef char            c8;
 * typedef int8_t          i8;
 * typedef int16_t         i16;
 * typedef int32_t         i24;
 * typedef int32_t         i32;
 * typedef int64_t         i64;
 *
 * typedef float           f32;
 * typedef double          f64;
 * typedef long double     f128; // platform depend type
 *
 * // bool type -------------------------
 * typedef unsigned char   b;
 *
 * #define CTYPE_FALSE (b)(0 != 0)
 * #define CTYPE_TRUE  (b)(0 == 0)
 *
 * // bus types defining (platform depend) ----------------------------------------------
 * typedef size_t      reg;    // platform depend type
 * typedef ptrdiff_t   sreg;   // platform depend type
 * //------------------------------------------------------------------
 */

#define PREPROCESSOR_C_TYPE_DETECTOR_uni_uni             ()
#define PREPROCESSOR_C_TYPE_DETECTOR_u8_u8               ()
#define PREPROCESSOR_C_TYPE_DETECTOR_u16_u16             ()
#define PREPROCESSOR_C_TYPE_DETECTOR_u24_u24             ()
#define PREPROCESSOR_C_TYPE_DETECTOR_u32_u32             ()
#define PREPROCESSOR_C_TYPE_DETECTOR_u64_u64             ()

#define PREPROCESSOR_C_TYPE_DETECTOR_c8_c8              ()
#define PREPROCESSOR_C_TYPE_DETECTOR_i8_i8              ()
#define PREPROCESSOR_C_TYPE_DETECTOR_i16_i16            ()
#define PREPROCESSOR_C_TYPE_DETECTOR_i24_i24            ()
#define PREPROCESSOR_C_TYPE_DETECTOR_i32_i32            ()
#define PREPROCESSOR_C_TYPE_DETECTOR_i64_i64            ()

#define PREPROCESSOR_C_TYPE_DETECTOR_f32_f32            ()
#define PREPROCESSOR_C_TYPE_DETECTOR_f64_f64            ()
#define PREPROCESSOR_C_TYPE_DETECTOR_f128_f128          ()
#define PREPROCESSOR_C_TYPE_DETECTOR_b_b                ()
#define PREPROCESSOR_C_TYPE_DETECTOR_reg_reg            ()
#define PREPROCESSOR_C_TYPE_DETECTOR_sreg_sreg          ()


//typedef int8_t int8;
//typedef int16_t int16;
//typedef int32_t int32;
//typedef int64_t int64;

//typedef uint8_t uint8;
//typedef uint16_t uint16;
//typedef uint32_t uint32;
//typedef uint64_t uint64;

//typedef uint8 byte;

#define PREPROCESSOR_C_TYPE_DETECTOR_int8_int8                  ()
#define PREPROCESSOR_C_TYPE_DETECTOR_int16_int16                ()
#define PREPROCESSOR_C_TYPE_DETECTOR_int32_int32                ()
#define PREPROCESSOR_C_TYPE_DETECTOR_int64_int64                ()
#define PREPROCESSOR_C_TYPE_DETECTOR_uint8_uint8                ()
#define PREPROCESSOR_C_TYPE_DETECTOR_uint16_uint16              ()
#define PREPROCESSOR_C_TYPE_DETECTOR_uint32_uint32              ()
#define PREPROCESSOR_C_TYPE_DETECTOR_uint64_uint64              ()


#endif // __PREPROCESSOR_TYPE_EQ_H__
