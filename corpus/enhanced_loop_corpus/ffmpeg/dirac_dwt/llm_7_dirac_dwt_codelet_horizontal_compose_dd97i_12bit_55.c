#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;
extern int32_t *b;
extern int32_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t prev_temp = 0;
    for (x = 1; x < w2; x++) {
        int32_t current_val = (b[x] - (unsigned int)((int)(prev_temp + (unsigned int)(b[x + w2]) + 2) >> 2));
        tmp[x] = current_val;
        prev_temp = b[x + w2 - 1];
    }
}
