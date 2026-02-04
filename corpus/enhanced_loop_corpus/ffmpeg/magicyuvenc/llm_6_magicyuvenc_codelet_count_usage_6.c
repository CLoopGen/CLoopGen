#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct PTable {
    int value;
    int64_t prob;
} PTable;

extern uint8_t *src;
extern int width;
extern int height;
extern PTable *counts;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t *prob_ptr;
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            prob_ptr = &counts[src[i]].prob;
            *prob_ptr += 1;
        }
        src += width;
    }
}
