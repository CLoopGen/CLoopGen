#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *b0;
extern int32_t *b1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < width; i++) {
    int temp = b1[i] + 1U;
    unsigned int shift_val = temp >> 1;
    b0[i] = b0[i] - (int)shift_val;
    
    if (b0[i] > 0) {
        b1[i] = b1[i] + b0[i];
    } else {
        b1[i] = b1[i] - 1;
    }
}
}
