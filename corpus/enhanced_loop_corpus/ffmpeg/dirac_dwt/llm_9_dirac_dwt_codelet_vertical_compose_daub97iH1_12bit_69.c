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
    int j;
    for (i = 0; i < width; i++) {
        int32_t temp_sum = b0[i] + (unsigned int)b2[i];
        int32_t scaled = (113 * temp_sum + 64) >> 7;
        unsigned int adjusted_b1 = (unsigned int)(b1[i]);
        for (j = 0; j < 2; j++) {
            adjusted_b1 = adjusted_b1 - scaled;
        }
        b1[i] = (int32_t)adjusted_b1;
    }
}
