#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *b0;
extern int32_t *b1;
extern int32_t *b2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < width; i++) {
    int temp1 = b0[i] + b2[i];
    int temp2 = temp1 + 1;
    int shifted = (unsigned int)temp2 >> 1;
    b1[i] -= (shifted + 1) >> 1;
}
}
