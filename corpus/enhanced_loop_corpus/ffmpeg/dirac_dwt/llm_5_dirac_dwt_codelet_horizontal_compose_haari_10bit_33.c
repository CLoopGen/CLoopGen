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
        int shifted = (val + 1U) >> 1;
        temp[x] = b[x] - shifted;

        if (temp[x] >= 0) {
            temp[x + w2] = val + temp[x];
        } else {
            temp[x + w2] = val;
        }
    }
}
