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
    int32_t prev_b2 = b2[0]; 
    for (i = 0; i < width; i++) {
        int32_t current_val = (int)(((unsigned int)(b2[i]) - ((int)(9U * b1[i] + 9U * b3[i] - b4[i] - b0[i] + 16) >> 5)));
        if (i > 0) {
            current_val = (current_val + prev_b2) & 0x7FFFFFFF; 
        }
        b2[i] = current_val;
        prev_b2 = current_val; 
    }
}
