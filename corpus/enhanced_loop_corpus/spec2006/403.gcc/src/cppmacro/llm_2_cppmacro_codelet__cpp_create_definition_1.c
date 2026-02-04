#include <stdio.h>

#include <inttypes.h>

struct ht_identifier {
    unsigned int len;
    const unsigned char *str;
};


enum node_type {
    NT_VOID = 0,
    NT_MACRO,
    NT_ASSERTION
};


typedef struct cpp_macro cpp_macro;

enum cpp_ttype {
    CPP_EQ = 0,
    CPP_NOT,
    CPP_GREATER,
    CPP_LESS,
    CPP_PLUS,
    CPP_MINUS,
    CPP_MULT,
    CPP_DIV,
    CPP_MOD,
    CPP_AND,
    CPP_OR,
    CPP_XOR,
    CPP_RSHIFT,
    CPP_LSHIFT,
    CPP_MIN,
    CPP_MAX,
    CPP_COMPL,
    CPP_AND_AND,
    CPP_OR_OR,
    CPP_QUERY,
    CPP_COLON,
    CPP_COMMA,
    CPP_OPEN_PAREN,
    CPP_CLOSE_PAREN,
    CPP_EQ_EQ,
    CPP_NOT_EQ,
    CPP_GREATER_EQ,
    CPP_LESS_EQ,
    CPP_PLUS_EQ,
    CPP_MINUS_EQ,
    CPP_MULT_EQ,
    CPP_DIV_EQ,
    CPP_MOD_EQ,
    CPP_AND_EQ,
    CPP_OR_EQ,
    CPP_XOR_EQ,
    CPP_RSHIFT_EQ,
    CPP_LSHIFT_EQ,
    CPP_MIN_EQ,
    CPP_MAX_EQ,
    CPP_HASH,
    CPP_PASTE,
    CPP_OPEN_SQUARE,
    CPP_CLOSE_SQUARE,
    CPP_OPEN_BRACE,
    CPP_CLOSE_BRACE,
    CPP_SEMICOLON,
    CPP_ELLIPSIS,
    CPP_PLUS_PLUS,
    CPP_MINUS_MINUS,
    CPP_DEREF,
    CPP_DOT,
    CPP_SCOPE,
    CPP_DEREF_STAR,
    CPP_DOT_STAR,
    CPP_ATSIGN,
    CPP_NAME,
    CPP_NUMBER,
    CPP_CHAR,
    CPP_WCHAR,
    CPP_OTHER,
    CPP_STRING,
    CPP_WSTRING,
    CPP_HEADER_NAME,
    CPP_COMMENT,
    CPP_MACRO_ARG,
    CPP_PADDING,
    CPP_EOF,
    N_TTYPES
};


enum builtin_type {
    BT_SPECLINE = 0,
    BT_DATE,
    BT_FILE,
    BT_BASE_FILE,
    BT_INCLUDE_LEVEL,
    BT_TIME,
    BT_STDC,
    BT_PRAGMA
};


union {
    cpp_macro *macro;
    struct answer *answers;
    enum cpp_ttype operator;
    enum builtin_type builtin;
};


struct cpp_hashnode {
    struct ht_identifier ident;
    unsigned short arg_index;
    unsigned char directive_index;
    unsigned char rid_code;
    enum node_type type : 8;
    unsigned char flags;
    union {
        cpp_macro *macro;
        struct answer *answers;
        enum cpp_ttype operator;
        enum builtin_type builtin;
    } value;
};


typedef struct cpp_hashnode cpp_hashnode;

typedef struct cpp_token cpp_token;

struct cpp_string {
    unsigned int len;
    const unsigned char *text;
};


union {
    cpp_hashnode *node;
    const cpp_token *source;
    struct cpp_string str;
    unsigned int arg_no;
    unsigned char c;
};


struct cpp_token {
    unsigned int line;
    unsigned short col;
    enum cpp_ttype type : 8;
    unsigned char flags;
    union {
        cpp_hashnode *node;
        const cpp_token *source;
        struct cpp_string str;
        unsigned int arg_no;
        unsigned char c;
    } val;
};


struct cpp_macro {
    cpp_hashnode **params;
    cpp_token *expansion;
    unsigned int line;
    unsigned int count;
    unsigned short paramc;
    unsigned int fun_like : 1;
    unsigned int variadic : 1;
    unsigned int syshdr : 1;
};


extern cpp_macro *macro;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access in reverse order (original is already reverse, but we make it forward consecutive)
    for (i = 0; i < macro->paramc; i++)
        macro->params[i]->arg_index = 0;
}
