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
    int32_t term1 = 9U * b1[i];
    int32_t term2 = 9U * b3[i];
    int32_t term3 = b4[i];
    int32_t term4 = b0[i];
    int32_t sum = term1 + term2 - term3 - term4 + 32;
    int32_t shift_val = sum >> 6;
    b2[i] = (int)((unsigned int)(b2[i]) - shift_val);
    b2[i] = (int)((unsigned int)(b2[i]) + ((shift_val * 3) >> 2));
}
}
