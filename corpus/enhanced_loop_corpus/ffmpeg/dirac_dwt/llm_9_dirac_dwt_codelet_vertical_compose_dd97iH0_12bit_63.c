#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *b0;
extern int32_t *b1;
extern int32_t *b2;
extern int32_t *b3;
extern int32_t *b4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width && i < 512; i++) {
        int32_t temp1 = 9U * b1[i];
        int32_t temp2 = 9U * b3[i];
        int32_t temp3 = temp1 + temp2;
        int32_t temp4 = temp3 - b4[i] - b0[i] + 8;
        int32_t temp5 = temp4 >> 4;
        int32_t temp6 = (unsigned int)(b2[i]) + temp5;
        b2[i] = (int)temp6;
    }
}
