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
    for (i = 0; i < *token_lim_ptr; i++) {
        if ((*token_ptr)[i].beg == NULL || (*token_ptr)[i].end == NULL) {
            continue;
        }
        new_tokens[i] = (*token_ptr)[i];
    }
}
