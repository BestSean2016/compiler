#include "ctp-parser.h"

static TIMap timap;

static IDENTIFIER_TOKEN ti_table[] = {
    {tok_enum, "enum"},     {tok_typedef, "typedef"},   {tok_char, "char"},
    {tok_int, "int"},       {tok_double, "double"},     {tok_short, "short"},
    {tok_signed, "signed"}, {tok_unsigned, "unsigned"}, {tok_struct, "struct"},
    {tok_eof, ""}};


//===----------------------------------------------------------------------===//
// Lexer
//===----------------------------------------------------------------------===//

static std::string IdentifierStr; // Filled in if tok_identifier
static double NumVal;             // Filled in if tok_number

//===----------------------------------------------------------------------===//
// initial token-identifier mapping
//===----------------------------------------------------------------------===//
void init_timap() {
  int i = 0;
  while (ti_table[i].token != tok_eof) {
    std::pair<std::string, TOKEN> p(ti_table[i].identifier, ti_table[i].token);
    timap.insert(p);
    ++i;
  }
}

void deinit_timap() { timap.clear(); }

TOKEN get_token() {
  TiMapIter iter = timap.find(IdentifierStr);
  return (iter == timap.end()) ? (tok_identifier) : (*iter).second;
}

static TOKEN char_token[256];
void init_char_token() {
  for (int i = 0; i < 256; ++i)
    char_token[i] = tok_error;

  char_token['#'] = tok_sharp;
  char_token['{'] = tok_left_brace;
  char_token['}'] = tok_right_brace;
  char_token['['] = tok_left_backet;
  char_token[']'] = tok_right_backet;
  char_token['<'] = tok_less;
  char_token['>'] = tok_larger;
  char_token['='] = tok_equal;
  char_token[','] = tok_comma;
  char_token[';'] = tok_semicolon;
  char_token['('] = tok_left_parenthese;
  char_token[')'] = tok_right_parenthese;
  char_token['\''] = tok_single_quote;
  char_token['\"'] = tok_double_quote;
  char_token['\\'] = tok_slash;
}

static char *get_char_token(char *lchar, char *line, TOKEN *token) {
  char *ptr = line;

  *token = char_token[*lchar];

  switch (*token) {
  case tok_sharp: //#
    break;
  case tok_left_brace: //{
    break;
  case tok_right_brace: //}
    break;
  case tok_left_backet: //[
    break;
  case tok_right_backet: //]
    break;
  case tok_less: //<
    break;
  case tok_larger: //>
    break;
  case tok_equal: //=
    break;
  case tok_comma: //,
    break;
  case tok_semicolon: //;
    break;
  case tok_left_parenthese: //(
    break;
  case tok_right_parenthese: //)
    break;
  case tok_single_quote: //'
    break;
  case tok_double_quote: //"
    break;
  case tok_slash: // /
    break;
  default:
    break;
  }

  *lchar = *ptr;
  if (*ptr) ++ptr;
  return ptr;
}

/// gettok - Return the next token from a line.
char *gettok(char* lchar, const char *line, TOKEN *token) {
  if (!line)
    return nullptr;

  char *ptr = (char *)line;

  // Skip any whitespace.
  while (*ptr && isspace((*lchar)))
    (*lchar) = *ptr++;

  if (isalpha((*lchar))) { // identifier: [a-zA-Z][a-zA-Z0-9]*
    IdentifierStr = (*lchar);
    while (*ptr && isalnum(((*lchar) = *ptr++)))
      IdentifierStr += (*lchar);

    *token = get_token();
    return ptr;
  }

  if (isdigit((*lchar)) || (*lchar) == '.') { // Number: [0-9.]+
    std::string NumStr;
    if (*ptr) {
      do {
        NumStr += (*lchar);
        (*lchar) = *ptr++;
      } while (*ptr && (isdigit((*lchar)) || (*lchar) == '.'));
    }

    NumVal = strtod(NumStr.c_str(), nullptr);
    *token = tok_number;
    return ptr;
  }

  ptr = get_char_token(lchar, ptr, token);
  if (*token != tok_error) return ptr;

  // Check for end of file.  Don't eat the EOF.
  if (!(*ptr)) {
    *token = tok_eof;
    return ptr;
  }

  // Otherwise, just return the character as its ascii value.
  *token = tok_error;
  return ptr;
}
