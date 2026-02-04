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
for (j = 0; j < height * width; j++) {
    int idx = j % width;
    counts[src[idx]].prob++;
    if ((j + 1) % width == 0) {
        src += width;
    }
}
}
