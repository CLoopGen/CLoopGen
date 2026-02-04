#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *b;
extern int32_t *temp;
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < w2; x++) {
        int val = b[x + w2];
        int offset_val = (val + 1U) >> 1;
        if (b[x] >= offset_val) {
            temp[x] = b[x] - offset_val;
            temp[x + w2] = val + temp[x];
        } else {
            temp[x] = b[x];
            temp[x + w2] = val;
        }
    }
}
