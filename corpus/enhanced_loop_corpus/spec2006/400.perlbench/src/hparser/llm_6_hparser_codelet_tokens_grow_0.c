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
    token_pos_t **t_ptr = token_ptr;
    int limit = *token_lim_ptr;
    token_pos_t *n_tokens = new_tokens;
    for (int j = 0; j < limit; j++) {
        n_tokens[j] = (*t_ptr)[j];
    }
}
