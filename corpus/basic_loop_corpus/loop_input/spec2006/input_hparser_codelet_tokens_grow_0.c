#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct token_pos {
    char *beg;
    char *end;
};

typedef struct token_pos token_pos_t;

token_pos_t **token_ptr;
int *token_lim_ptr;
token_pos_t *new_tokens;
int i;

static token_pos_t *allocated_token_array;
static int allocated_size;

void init_vars() {
    allocated_size = 16777216; // ~16M elements to target ~0.01 sec runtime
    
    // Allocate backing storage for tokens
    allocated_token_array = calloc(allocated_size, sizeof(token_pos_t));
    if (!allocated_token_array) {
        exit(1);
    }
    
    // Initialize each token's pointers to valid memory
    for (int j = 0; j < allocated_size; j++) {
        allocated_token_array[j].beg = malloc(1);
        allocated_token_array[j].end = malloc(1);
        if (!allocated_token_array[j].beg || !allocated_token_array[j].end) {
            exit(1);
        }
        *(allocated_token_array[j].beg) = 'a';
        *(allocated_token_array[j].end) = 'b';
    }
    
    // Allocate and initialize the double pointer
    token_ptr = malloc(sizeof(token_pos_t*));
    if (!token_ptr) {
        exit(1);
    }
    *token_ptr = allocated_token_array;
    
    // Allocate and initialize limit pointer
    token_lim_ptr = malloc(sizeof(int));
    if (!token_lim_ptr) {
        exit(1);
    }
    *token_lim_ptr = allocated_size;
    
    // Allocate new_tokens array
    new_tokens = calloc(allocated_size, sizeof(token_pos_t));
    if (!new_tokens) {
        exit(1);
    }
}