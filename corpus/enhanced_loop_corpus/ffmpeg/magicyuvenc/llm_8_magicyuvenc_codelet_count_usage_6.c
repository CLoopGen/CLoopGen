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
for (j = 0; j < height; j++) {
    int64_t *local_counts = &counts[src[0]].prob;
    for (i = 1; i < width; i++) {
        counts[src[i]].prob++;
    }
    src += width;
}
}
