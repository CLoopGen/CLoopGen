#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *b;
extern int16_t *temp;
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < w2; x++) {
        int b_val = b[x];
        int b_next = b[x + w2];
        temp[x] = b_val - ((b_next + 1U) >> 1);
        temp[x + w2] = b_next + temp[x];
    }
}
