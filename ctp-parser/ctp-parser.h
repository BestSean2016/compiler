#ifndef CTPPARSER_H
#define CTPPARSER_H

//#include "llvm/ADT/APFloat.h"
//#include "llvm/ADT/STLExtras.h"
//#include "llvm/IR/BasicBlock.h"
//#include "llvm/IR/Constants.h"
//#include "llvm/IR/DerivedTypes.h"
//#include "llvm/IR/Function.h"
//#include "llvm/IR/IRBuilder.h"
//#include "llvm/IR/LLVMContext.h"
//#include "llvm/IR/Module.h"
//#include "llvm/IR/Type.h"
//#include "llvm/IR/Verifier.h"
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <memory>
#include <string>
#include <vector>

// using namespace llvm;

typedef enum TOKEN {
    tok_eof = -1,
    tok_include = -2,                       // #include
    tok_ifndef = -3,                        // #ifndef
    tok_endif = -4,                         // #endif
    tok_line_comment = -5,                  // //
    tok_block_comment_start = -6,           // /*
    tok_block_comment_end = -7,             // */
    tok_enum = -8,                          // enum
    tok_typedef = -9,                       // typedef
    tok_char = -10,                         // char
    tok_char_ptr = -11,                     // char*
    tok_char_array = -12,                   // char[]
    tok_define = -13,                       // #define
    tok_int = -14,                          // int
    tok_double = -15,                       // double
    tok_short = -16,                        // short
    tok_signed = -17,                       // signed
    tok_unsigned = -18,                     // unsigned
    tok_sharp_else = -19,                   // #else
    tok_sharp_if   = -20,                   // #if
    tok_sharp = -21,                        // #
    tok_comma = -22,                        // ,
    tok_semicolon = -23,                    // ;
    tok_left_brace = -24,                   // {
    tok_right_brace = -25,                  // }
    tok_left_backet = -26,                  // [
    tok_right_backet = -27,                 // ]
    tok_left_parenthese = -28,              // (
    tok_right_parenthese = -29,             // )
    tok_single_quote = -30,                 // '
    tok_double_quote = -31,                 // "
    tok_equal        = -32,                 // =
    tok_larger       = -33,                 // >
    tok_less         = -34,                 // <
    tok_descripte    = -35,                 // ///
    tok_pragma       = -36,                 // #pragma
    tok_struct       = -37,                 // struct
    tok_identifier   = -38,
    tok_number       = -39,
    tok_error        = -40,
    tok_slash        = -41,                 // /
} TOKEN;

typedef enum DataType {
    DataType_Integer = 0,
    DataType_String  = 1,
    DataType_Char    = 2,
    DataType_Numeric = 3,
} DataType;


typedef struct CType {
    DataType type;
    int      size;
    bool     issigned;
} CType;


typedef struct IDENTIFIER_TOKEN {
    TOKEN token;
    std::string identifier;
} IDENTIFIER_TOKEN;

typedef std::map<std::string, TOKEN> TIMap;
typedef TIMap::iterator TiMapIter;


//===----------------------------------------------------------------------===//
/// initial token-identifier mapping
//===----------------------------------------------------------------------===//
extern void init_timap();
//===----------------------------------------------------------------------===//
/// de-initial token-identifier mapping
//===----------------------------------------------------------------------===//
extern void deinit_timap();
//===----------------------------------------------------------------------===//
/// Lexer
//===----------------------------------------------------------------------===//
extern TOKEN get_token();
/// gettok - Return the next token from a line.
extern char* gettok(char* lchar, const char* line, TOKEN* token);
extern void init_char_token();

#endif // CTPPARSER_H
