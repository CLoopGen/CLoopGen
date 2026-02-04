#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int stride;
extern  int xStride;
extern int i;
extern unsigned int temp[8];
extern int32_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        unsigned int val1 = block[stride * i + xStride * 0];
        unsigned int val2 = block[stride * i + xStride * 1];
        if (val1 >= val2) {
            temp[2 * i + 0] = val1 + val2;
            temp[2 * i + 1] = val1 - val2;
        } else {
            temp[2 * i + 0] = val2 - val1;
            temp[2 * i + 1] = val2 + val1;
        }
    }
}
