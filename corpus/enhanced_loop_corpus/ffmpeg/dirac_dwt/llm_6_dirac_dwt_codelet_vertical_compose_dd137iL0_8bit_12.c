#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *b0;
extern int16_t *b1;
extern int16_t *b2;
extern int16_t *b3;
extern int16_t *b4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t temp_load_b2, temp_load_b1, temp_load_b3, temp_load_b4, temp_load_b0;
    for (i = 0; i < width; i++) {
        temp_load_b2 = b2[i];
        temp_load_b1 = b1[i];
        temp_load_b3 = b3[i];
        temp_load_b4 = b4[i];
        temp_load_b0 = b0[i];
        b2[i] = (int)(((unsigned int)temp_load_b2) - ((int)(9U * temp_load_b1 + 9U * temp_load_b3 - temp_load_b4 - temp_load_b0 + 16) >> 5));
    }
}
