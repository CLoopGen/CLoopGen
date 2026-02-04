#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

struct token_pos {
    char *beg;
    char *end;
};

typedef struct token_pos token_pos_t;

token_pos_t **token_ptr;
int *token_lim_ptr;
token_pos_t *new_tokens;
int i;

void init_vars() {
    const int data_size = 1 << 20; // 1MB of tokens: 2^20 elements

    // Allocate token_pos_t array
    token_pos_t *tokens = calloc(data_size, sizeof(token_pos_t));
    if (!tokens) exit(1);

    // Initialize each token with valid pointers (pointing to dummy memory)
    char *dummy_mem = malloc(data_size * 2);
    if (!dummy_mem) exit(1);
    for (int j = 0; j < data_size; j++) {
        tokens[j].beg = dummy_mem + j;
        tokens[j].end = dummy_mem + j + 1;
    }

    // Allocate pointer array for token_ptr indirection
    token_pos_t **ptr_array = malloc(sizeof(token_pos_t*));
    if (!ptr_array) exit(1);
    ptr_array[0] = tokens;

    // Allocate and set token limit
    int *lim = malloc(sizeof(int));
    if (!lim) exit(1);
    *lim = data_size;

    // Allocate destination array
    token_pos_t *dst = calloc(data_size, sizeof(token_pos_t));
    if (!dst) exit(1);

    // Assign to global extern variables
    token_ptr = ptr_array;
    token_lim_ptr = lim;
    new_tokens = dst;
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}