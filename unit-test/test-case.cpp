#include <gtest/gtest.h>
#include <iostream>
#include "ctp-parser.h"


using namespace std;

TEST(test_gettok, 1_0) {
    init_timap();
    init_char_token();

    TOKEN token;
    char* str = "typedef struct test { int a; char b; } test;";
    char lchar = ' ';
    char* ptr= gettok(&lchar, str, &token);
    EXPECT_EQ(token, tok_typedef);
    EXPECT_EQ(ptr, str + strlen("typedef "));

    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_struct);
    EXPECT_EQ(ptr, str + strlen("typedef struct "));

    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_identifier);
    EXPECT_EQ(ptr, str + strlen("typedef struct test "));

    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_left_brace);
    EXPECT_EQ(ptr, str + strlen("typedef struct test { "));

    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_int);
    EXPECT_EQ(ptr, str + strlen("typedef struct test { int "));


    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_identifier);
    EXPECT_EQ(ptr, str + strlen("typedef struct test { int a;"));

    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_semicolon);
    EXPECT_EQ(ptr, str + strlen("typedef struct test { int a; "));

    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_char);
    EXPECT_EQ(ptr, str + strlen("typedef struct test { int a; char "));


    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_identifier);
    EXPECT_EQ(ptr, str + strlen("typedef struct test { int a; char b;"));

    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_semicolon);
    EXPECT_EQ(ptr, str + strlen("typedef struct test { int a; char b; "));

    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_right_brace);
    EXPECT_EQ(ptr, str + strlen("typedef struct test { int a; char b; } "));

    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_identifier);
    EXPECT_EQ(ptr, str + strlen("typedef struct test { int a; char b; } test;"));

    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_semicolon);
    EXPECT_EQ(*ptr, '\0');


    deinit_timap();
}


TEST(test_gettok, 1_1) {
    init_timap();
    init_char_token();

    TOKEN token;
    char* str = "typedef struct test{int a;char b;}test;";
    char lchar = ' ';
    char* ptr= gettok(&lchar, str, &token);
    EXPECT_EQ(token, tok_typedef);
    EXPECT_EQ(ptr, str + strlen("typedef "));

    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_struct);
    EXPECT_EQ(ptr, str + strlen("typedef struct "));

    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_identifier);
    EXPECT_EQ(ptr, str + strlen("typedef struct test{"));

    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_left_brace);
    EXPECT_EQ(ptr, str + strlen("typedef struct test{i"));

    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_int);
    EXPECT_EQ(ptr, str + strlen("typedef struct test{int "));


    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_identifier);
    EXPECT_EQ(ptr, str + strlen("typedef struct test{int a;"));

    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_semicolon);
    EXPECT_EQ(ptr, str + strlen("typedef struct test{int a;c"));

    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_char);
    EXPECT_EQ(ptr, str + strlen("typedef struct test{int a;char "));


    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_identifier);
    EXPECT_EQ(ptr, str + strlen("typedef struct test{int a;char b;"));

    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_semicolon);
    EXPECT_EQ(ptr, str + strlen("typedef struct test{int a;char b;}"));

    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_right_brace);
    EXPECT_EQ(ptr, str + strlen("typedef struct test{int a;char b;}t"));

    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_identifier);
    EXPECT_EQ(ptr, str + strlen("typedef struct test{int a;char b;}test;"));

    ptr = gettok(&lchar, ptr, &token);
    EXPECT_EQ(token, tok_semicolon);
    EXPECT_EQ(*ptr, '\0');


    deinit_timap();
}
