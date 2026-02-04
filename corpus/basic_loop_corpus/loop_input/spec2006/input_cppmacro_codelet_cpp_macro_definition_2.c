#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

unsigned int i;
unsigned int len;
cpp_macro *macro;

static cpp_hashnode **generated_params;
static cpp_hashnode *generated_hashnodes;
static unsigned char *generated_strings_pool;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64MB to ensure loop runtime around 0.01s
    const unsigned short target_paramc = 100000; // Large enough for significant loop, small enough to fit

    macro = (cpp_macro *)calloc(1, sizeof(cpp_macro));
    generated_params = (cpp_hashnode **)calloc(target_paramc, sizeof(cpp_hashnode *));
    generated_hashnodes = (cpp_hashnode *)calloc(target_paramc, sizeof(cpp_hashnode));
    generated_strings_pool = (unsigned char *)malloc(total_data_size);

    if (!macro || !generated_params || !generated_hashnodes || !generated_strings_pool) {
        exit(1);
    }

    macro->params = generated_params;
    macro->paramc = target_paramc;
    macro->fun_like = 1;
    macro->variadic = 0;
    macro->syshdr = 0;
    macro->line = 1;
    macro->count = 0;
    macro->expansion = NULL;

    size_t pool_offset = 0;
    for (unsigned int idx = 0; idx < target_paramc; ++idx) {
        size_t str_len = (idx % 15) + 5; // vary string length between 5 and 19
        if (pool_offset + str_len >= total_data_size) {
            str_len = total_data_size - pool_offset - 1;
        }
        for (size_t j = 0; j < str_len; ++j) {
            generated_strings_pool[pool_offset + j] = 'a' + (j % 26);
        }
        generated_strings_pool[pool_offset + str_len] = '\0';

        generated_hashnodes[idx].ident.len = str_len;
        generated_hashnodes[idx].ident.str = &generated_strings_pool[pool_offset];
        generated_hashnodes[idx].arg_index = idx;
        generated_hashnodes[idx].directive_index = 0;
        generated_hashnodes[idx].rid_code = 0;
        generated_hashnodes[idx].type = NT_MACRO;
        generated_hashnodes[idx].flags = 0;
        generated_hashnodes[idx].value.macro = NULL;

        generated_params[idx] = &generated_hashnodes[idx];

        pool_offset += str_len + 1;
        if (pool_offset >= total_data_size) {
            pool_offset = 0; // wrap around if needed
        }
    }

    i = 0;
    len = 0;
}