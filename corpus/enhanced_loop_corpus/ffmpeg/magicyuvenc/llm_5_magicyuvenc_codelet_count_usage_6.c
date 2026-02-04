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
    for (i = 0; i < width; i++) {
        int index = src[i];
        if (index < 0) continue;
        counts[index].prob++;
    }
    src += width;
}
}
