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
    int n = *token_lim_ptr;
    for (i = 0; i < n; i += 2) {
        new_tokens[i] = (*token_ptr)[i];
        if (i + 1 < n)
            new_tokens[i + 1] = (*token_ptr)[i + 1];
    }
}
