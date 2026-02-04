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
    for (i = 0; i < width; i++) {
        int32_t temp1 = b1[i];
        int32_t temp3 = b3[i];
        int32_t temp_sum = 9U * temp1 + 9U * temp3 - b4[i] - b0[i] + 16;
        unsigned int shifted = (unsigned int)(temp_sum >> 5);
        b2[i] = (int)((unsigned int)(b2[i]) - shifted);
    }
}
