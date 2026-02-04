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
    int double_limit = *token_lim_ptr * 2;
    for (i = 0; i < double_limit; i += 2) {
        int idx = i / 2;
        new_tokens[idx] = (*token_ptr)[idx];
    }
}
