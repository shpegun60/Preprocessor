/*
 *	CREATED BY SHPEGUN60
 *
 *  KEYWORD DETECT MACROCES
 */

#ifndef __PREPROCESSOR_KEYWORD_EQ_H__
#define __PREPROCESSOR_KEYWORD_EQ_H__ 1


/*********************************************************************************************************************
 * C/C++ keyword detector macro
 *
 *      PREPROCESSOR_KEYWORD_EQ(return, return) // expands to 1
 *      PREPROCESSOR_KEYWORD_EQ(return, case)   // expands to 0
 *      PREPROCESSOR_KEYWORD_DETECT(for)        // expands to 1
 *
 */
#define PREPROCESSOR_KEYWORD_EQ(x, y)           PREPROCESSOR_KEYWORD_DETECT_IMPL(x, y)
#define PREPROCESSOR_KEYWORD_DETECT(x)          PREPROCESSOR_KEYWORD_DETECT_IMPL(x, x)
#define PREPROCESSOR_KEYWORD_DETECT_IMPL(x, y)  PREPROCESSOR_IS_TUPLE_FAST(PREPROCESSOR_C_KEYWORD_DETECTOR_##x##_##y)


#define PREPROCESSOR_C_KEYWORD_DETECTOR_auto_auto                     ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_break_break                   ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_case_case                     ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_char_char                     ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_const_const                   ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_continue_continue             ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_default_default               ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_do_do                         ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_double_double                 ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_else_else                     ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_enum_enum                     ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_extern_extern                 ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_float_float                   ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_for_for                       ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_goto_goto                     ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_if_if                         ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_inline_inline                 ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_int_int                       ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_long_long                     ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_register_register             ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_restrict_restrict             ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_return_return                 ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_short_short                   ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_signed_signed                 ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_sizeof_sizeof                 ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_static_static                 ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_struct_struct                 ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_switch_switch                 ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_typedef_typedef               ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_union_union                   ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_unsigned_unsigned             ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_void_void                     ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_volatile_volatile             ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR_while_while                   ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR__Alignas__Alignas             ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR__Alignof__Alignof             ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR__Atomic__Atomic               ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR__Bool__Bool                   ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR__Complex__Complex             ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR__Generic__Generic             ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR__Imaginary__Imaginary         ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR__Noreturn__Noreturn           ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR__Static_assert__Static_assert ()
#define PREPROCESSOR_C_KEYWORD_DETECTOR__Thread_local__Thread_local   ()


#endif // __PREPROCESSOR_KEYWORD_EQ_H__
