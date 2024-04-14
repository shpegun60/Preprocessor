#include "preprocessor_test.h"
#include "preprocessor.h"


///* Type your code here, or load an example. */
int preprocessor_test()
{
    // preprocessor_complement.h --------------------------------------------
    int _1 = PREPROCESSOR_COMPL(0); // expand to 1
	
    // preprocessor_stringify.h ---------------------------------------------
    char _2[] = PREPROCESSOR_STRINGIFY(expr);
    char _3[] = PREPROCESSOR_STRINGIFY_VARIADIC(expr1, expr2, expr3);
	
    // preprocessor_symbol.h ---------------------------------------------
    int _4 PREPROCESSOR_COMMA_IF_IMPL(1)() PREPROCESSOR_COMMA_IF_IMPL(0)()  _5 PREPROCESSOR_COMMA_POINT()
    int _6 PREPROCESSOR_COMMA_POINT_VARIADIC(...)
	
    // preprocessor_arithmetic.h ---------------------------------------------
    int _7 = PREPROCESSOR_INC(1); // expand to 2
    int _8 = PREPROCESSOR_DEC(9); // expand to 8
	
    // preprocessor_base.h ---------------------------------------------
    int _9 = PREPROCESSOR_EXPAND(10);
    char _10[] = PREPROCESSOR_MACRO_DEBUG(expr);
	
    #define TXT11 "1234566"
    char _11[] = PREPROCESSOR_EVAL(PREPROCESSOR_DEFER20(TXT11));
    #undef TXT11
	
    // preprocessor_boolean.h ---------------------------------------------
    int _12 =  PREPROCESSOR_BOOL(1)   ; // expand to 1
    int _13 =  PREPROCESSOR_BOOL(0)   ; // expand to 0
    int _14 =  PREPROCESSOR_BOOL(aaa) ; // expand to 1 (aaa - is not defined)
    int _15 =  PREPROCESSOR_BOOL()    ; // expand to 1 (empty parameter)
	
    int _16 =  PREPROCESSOR_NOT(1);     // expand to 0
    int _17 =  PREPROCESSOR_NOT(0);     // expand to 1
    int _18 =  PREPROCESSOR_NOT(aaa);   // expand to 0 (aaa - is not defined than equal 1)
    int _19 =  PREPROCESSOR_NOT();      // expand to 0 (empty parameter than equal 1)


    // preprocessor_concatenation.h ---------------------------------------------
    char _20[] = PREPROCESSOR_MACRO_DEBUG(PREPROCESSOR_CONCAT(var1, var2));
    char _21[] = PREPROCESSOR_MACRO_DEBUG(PREPROCESSOR_CONCAT3(var1, var2, var3));
    char _22[] = PREPROCESSOR_MACRO_DEBUG(PREPROCESSOR_CONCAT4(var1, var2, var3, var4));
	
    // preprocessor_div.h ---------------------------------------------
    int _23 =  PREPROCESSOR_DIV_CHECKED(10, 2);     // expands to 5
	
    // preprocessor_if.h ---------------------------------------------
    int _24 =   PREPROCESSOR_IF(1)(24);
    int _25 =   PREPROCESSOR_IF_ELSE(1)(
                1,
                0
            );
			
    // preprocessor_serial.h ---------------------------------------------
    char _26[] = PREPROCESSOR_MACRO_DEBUG(PREPROCESSOR_SERIAL_ID(123));
	
    // preprocessor_nat_eq.h ---------------------------------------------
    int _453 = PREPROCESSOR_NAT_DETECT(for);// expands to 0
    int _27 = PREPROCESSOR_NAT_DETECT(99);// expands to 1
	
    int _28 = PREPROCESSOR_NAT_EQ(10, 10) ;// expands to 1
    int _29 = PREPROCESSOR_NAT_EQ(10, 11);         // expands to 0
	
    // preprocessor_keyword_eq.h ---------------------------------------------
    int _30 = PREPROCESSOR_KEYWORD_EQ(return, return); // expands to 1
    int _31 = PREPROCESSOR_KEYWORD_EQ(return, case) ;  // expands to 0
	
    int _32 = PREPROCESSOR_KEYWORD_DETECT(for)     ;   // expands to 1
	
    // preprocessor_template.h ---------------------------------------------
    char _33[] = PREPROCESSOR_MACRO_DEBUG(TEMPLATE(sum, int, double));

    int TEMPLATE(sum, int, double, float) = 0;
	
    // preprocessor_detection.h ---------------------------------------------
    int _34 = PREPROCESSOR_IS_PROBE(PREPROCESSOR_PROBE());      // Expands to 1
    int _35 = PREPROCESSOR_IS_PROBE(xxx);                       // Expands to 0
	
    int _36 = PREPROCESSOR_IS_PAREN(());  // Expands to 1
    int _37 = PREPROCESSOR_IS_PAREN(xxx); // Expands to 0
	
    // preprocessor_comparsion.h ---------------------------------------------
    #define foo(x) x
    #define bar(x) x
	
    int _38 = PREPROCESSOR_PRIMITIVE_COMPARE(foo, bar); // Expands to 1
    int _39 = PREPROCESSOR_PRIMITIVE_COMPARE(foo, foo); // Expands to 0
	
    int _40 = PREPROCESSOR_NOT_EQUAL(foo, bar);    // Expands to 1
    int _41 = PREPROCESSOR_NOT_EQUAL(foo, foo);    // Expands to 0
    int _42 = PREPROCESSOR_NOT_EQUAL(foo, unfoo);  // Expands to 1
	
    int _43 = PREPROCESSOR_EQUAL(foo, bar);        // Expands to 0
    int _44 = PREPROCESSOR_EQUAL(foo, foo);        // Expands to 1
    int _45 = PREPROCESSOR_EQUAL(foo, unfoo);      // Expands to 0 (unfoo is not defined)
	
    #undef foo
    #undef bar
	
    // preprocessor_logical.h ---------------------------------------------
    int _46 = PREPROCESSOR_PRIMITIVE_NOT(0);      // Expands to 1
    int _50 = PREPROCESSOR_PRIMITIVE_NOT(1);      // Expands to 0
	
    int _47 = PREPROCESSOR_BIT_AND(1)(47);      // Expands to 47
	
    int _48 = PREPROCESSOR_OR(0,1);      // Expands to 1
    int _49 = PREPROCESSOR_OR(0,0);      // Expands to 0
	
    int _51 = PREPROCESSOR_OR3(1, 0, 0);      // Expands to 1
	
    int _52 = PREPROCESSOR_AND(1,1) ;      // Expands to 1
    int _53 = PREPROCESSOR_AND(1,0) ;      // Expands to 0
	
    int _54 = PREPROCESSOR_EXPAND(PREPROCESSOR_XOR(1,0)) ;      // Expands to 1
    int _55 = PREPROCESSOR_XOR(1,1) ;      // Expands to 0
	
    int _56 = PREPROCESSOR_BOOL_EQ(1,1) ;      // Expands to 1
    int _57 = PREPROCESSOR_BOOL_EQ(1,0) ;      // Expands to 0
	
    int _58 =  PREPROCESSOR_BITAND(0)(x,y,z)  ;      // Expands to 0
    int _59 =  PREPROCESSOR_BITAND(1)(1); // Expands to 1
	
    // preprocessor_tuple.h ---------------------------------------------
    int _60 =  PREPROCESSOR_IS_DOUBLE_TUPLE_BEGINNING(); // expands to 0
    int _61 =  PREPROCESSOR_IS_DOUBLE_TUPLE_BEGINNING(2); // expands to 0
    int _62 =  PREPROCESSOR_IS_DOUBLE_TUPLE_BEGINNING((2)); // expands to 0
    int _63 =  PREPROCESSOR_IS_DOUBLE_TUPLE_BEGINNING((2) (3)); // expands to 1
	
    int _64 =  PREPROCESSOR_IS_UNTUPLE_FAST(PREPROCESSOR_TUPLE_MAKE(x, y, z)); // expand to 0
    int _65 =  PREPROCESSOR_IS_UNTUPLE_FAST(x);// expand to 1
    int _66 =  PREPROCESSOR_IS_UNTUPLE_FAST(());// expand to 0
	
    int _67 =  PREPROCESSOR_IS_TUPLE_FAST(PREPROCESSOR_TUPLE_MAKE(x, y, z)); // expand to 1
    int _68 =  PREPROCESSOR_IS_TUPLE_FAST(x); // expand to 0
	
    int _123 =  PREPROCESSOR_UNTUPLE((68)); // expands just to 68 (deletes parenthesis)
    char _69[] = PREPROCESSOR_MACRO_DEBUG( PREPROCESSOR_TUPLE_MAKE(x,y,z));
    char _70[] = PREPROCESSOR_MACRO_DEBUG( PREPROCESSOR_TUPLE_APPEND(x1, (x, y, z)));// expands to (x, y, z, x1)
    char _71[] = PREPROCESSOR_MACRO_DEBUG( PREPROCESSOR_TUPLE_PREPEND(x1, (x, y, z)));// expands to (x1, x, y, z)
	
    char _72[] = PREPROCESSOR_MACRO_DEBUG( PREPROCESSOR_TUPLE_MERGE((x1, y1, z1), (x, y, z))); // expands to (x1, y1, z1, x, y, z)
    char _73[] = PREPROCESSOR_MACRO_DEBUG( PREPROCESSOR_TUPLE_MERGE_VARIADIC((1,2,3) ,(6,5,4), (3,2,1))); // expands to (1,2,3 , 6,5,4 , 3,2,1)
    char _74[] = PREPROCESSOR_MACRO_DEBUG( PREPROCESSOR_TUPLE_TAIL((x,y,z))); // expands to y,z
    char _75[] = PREPROCESSOR_MACRO_DEBUG( PREPROCESSOR_TUPLE_HEAD((x,y,z))); // expands to x
	
    int _76 =  PREPROCESSOR_TUPLE_COUNT((x,y,z, x1)); // expands to 4
    int _77 = PREPROCESSOR_TUPLE_IS_SINGLE((x,y,z, x1)); // expands to 0
    int _78 = PREPROCESSOR_TUPLE_IS_SINGLE((x));           // expands to 1
    int _79 = PREPROCESSOR_TUPLE_IS_NOT_EMPTY((x,y,z));   // expands to 1
    int _80 = PREPROCESSOR_TUPLE_IS_NOT_EMPTY(());        // expands to 0
    int _81 = PREPROCESSOR_TUPLE_GET(1)(0, 1, 2);         // expands to 1
    char _82[] = PREPROCESSOR_MACRO_DEBUG( PREPROCESSOR_TUPLE_REMOVE(1)(x, y, z)); // expands to x , z

    #define TUPLE_FOO(x) printf("%d", x)
    char _121[] = PREPROCESSOR_MACRO_DEBUG(PREPROCESSOR_TUPLE_FOR_EACH_ELEM(TUPLE_FOO, PREPROCESSOR_COMMA_POINT, (1,2,3) ,(6,5,4), (3,2,1)));
    char _83[] = PREPROCESSOR_MACRO_DEBUG( PREPROCESSOR_TUPLE_REMOVE(1)(x, y, z)); // expands to x , z
    #undef TUPLE_FOO
	
    #define TUPLE_FOO(par, x) printf(par); PREPROCESSOR_CONCAT(myFoo, PREPROCESSOR_TUPLE_COUNT(x)) x
    char _84[] = PREPROCESSOR_MACRO_DEBUG( PREPROCESSOR_TUPLE_FOR_EACH_PARAMETER("next par------", TUPLE_FOO, PREPROCESSOR_COMMA_POINT, (1,2,3,4), (6,5), (3)));
    #undef TUPLE_FOO
	
    // preprocessor_type_eq.h ---------------------------------------------
    int _85 =   PREPROCESSOR_TYPE_EQ(int, int);      // expands to 1
    int _86 =   PREPROCESSOR_TYPE_EQ(float, int);   // expands to 0
    int _87 =   PREPROCESSOR_TYPE_DETECT(int);        // expands to 1
	
    // preprocessor_char_eq.h ---------------------------------------------
    int _88 =   PREPROCESSOR_CHAR_IS_LOWERCASE(l);       // expands to 1
    int _89 =   PREPROCESSOR_CHAR_IS_LOWERCASE(L);       // expands to 0
	
    // preprocessor_cycle.h ---------------------------------------------
    #define FOO(x) x
    char _90[] = PREPROCESSOR_MACRO_DEBUG(  PREPROCESSOR_FOR_EACH(FOO, PREPROCESSOR_COMMA_POINT, A,B,C,D) );
    #undef FOO
	
    // preprocessor_arguments.h ---------------------------------------------
    int _91 =   PREPROCESSOR_GET_ARG(2)(0, 1, 2);// expands to 2
	
    char _92[] = PREPROCESSOR_MACRO_DEBUG( PREPROCESSOR_ARGS_HEAD(x,y,z) ); // expands to x
    char _110[] = PREPROCESSOR_MACRO_DEBUG( PREPROCESSOR_ARGS_TAIL(x,y,z) ); // expands to y,z
    char _111[] = PREPROCESSOR_MACRO_DEBUG( PREPROCESSOR_ARGS_SND(x,y,z) ); // expands to y
    char _bbb = (char)PREPROCESSOR_GET_ARG(2)(111,222,333); // expands to y
	
    char _93[] = PREPROCESSOR_MACRO_DEBUG( PREPROCESSOR_REMOVE_ARG(1)(x, y, z) ); // expands to x, z
	
    int _94 =   PREPROCESSOR_ARGS_EMPTY(x, y, z); // expand to 0
    int _95 =   PREPROCESSOR_ARGS_EMPTY();           // expand to 1
	
    int _96 =   PREPROCESSOR_ARGS_NOT_EMPTY();           // expand to 0
    int _97 =   PREPROCESSOR_ARGS_NOT_EMPTY(x, y, z);    // expand to 1
	
    int _98 =   PREPROCESSOR_ARGS_COUNT();             // expand to 0
    int _99 =   PREPROCESSOR_ARGS_COUNT(x,y,z);       // expand to 3
    int _100 =   PREPROCESSOR_ARGS_COUNT(x, PREPROCESSOR_TUPLE_MAKE(1,2,3)); // expand to 2
	
    int _101 =   PREPROCESSOR_SIMPLE_HAS_ARGS();          // expands to 0
    int _102 =   PREPROCESSOR_SIMPLE_HAS_ARGS(,);         // expands to 0
    int _103 =   PREPROCESSOR_SIMPLE_HAS_ARGS(, a);       // expands to 0
    int _104 =   PREPROCESSOR_SIMPLE_HAS_ARGS(a,b,c);     // expands to 1
	
    int _105 =   PREPROCESSOR_ARGS_CONTAINS_COMMA(x);      // expands to 0
    int _106 =   PREPROCESSOR_ARGS_CONTAINS_COMMA();       // expands to 0
    int _107 = PREPROCESSOR_ARGS_CONTAINS_COMMA(x,y);    // expands to 1
    int _108 = PREPROCESSOR_ARGS_IS_SINGLE(x);      // expands to 1
    int _109 = PREPROCESSOR_ARGS_IS_SINGLE(,);      // expands to 0

    PREPROCESSOR_UNUSED_SERIAL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10,
                               _11, _12, _13, _14, _15, _16, _17, _18, _19, _20,
                               _21, _22, _23, _24, _25, _26, _27, _28, _29, _30,
                               _31, _32, _33, _34, _35, _36, _37, _38, _39, _40,
                               _41, _42, _43, _44, _45, _46, _47, _48, _49, _50);

    PREPROCESSOR_UNUSED_SERIAL(_51, _52, _53, _54, _55, _56, _57, _58, _59, _60,
                               _61, _62, _63, _64, _65, _66, _67, _68, _69, _70,
                               _71, _72, _73, _74, _75, _76, _77, _78, _79, _80,
                               _81, _82, _83, _84, _85, _86, _87, _88, _89, _90,
                               _91, _92, _93, _94, _95, _96, _97, _98, _99, _100);

    PREPROCESSOR_UNUSED_SERIAL(_101, _102, _103, _104, _105, _106, _107, _108, _109, _110, _111, _121, _bbb, _123,
                               _453, TEMPLATE(sum, int, double, float));
    return 0;
}
