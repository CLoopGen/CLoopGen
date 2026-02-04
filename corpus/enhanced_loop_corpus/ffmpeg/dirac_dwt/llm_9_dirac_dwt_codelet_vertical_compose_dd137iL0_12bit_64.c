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
    int32_t term3 = b4[i] + b0[i];
    int32_t sum = term1 + term2 - term3 + 16;
    int32_t shift_val = sum >> 5;
    int32_t unsigned_b2 = (unsigned int)(b2[i]);
    b2[i] = (int)(unsigned_b2 - shift_val);
}
}
