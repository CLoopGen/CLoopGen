#include <stdio.h>

#include <inttypes.h>

struct token_pos {
    char *beg;
    char *end;
};


typedef struct token_pos token_pos_t;

extern token_pos_t **token_ptr;
extern int *token_lim_ptr;
extern token_pos_t *new_tokens;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    token_pos_t **local_token_ptr = token_ptr;
    int limit = *token_lim_ptr;
    token_pos_t *local_new_tokens = new_tokens;
    for (i = 0; i < limit; i++) {
        local_new_tokens[i] = (*local_token_ptr)[i];
    }
}
