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
    int32_t sum = b0[i] + (unsigned int)b2[i];
    int32_t term = (113 * sum + 64) >> 7;
    unsigned int val = (unsigned int)(b1[i]);
    b1[i] = val - term;
    b1[i] = (b1[i] > val) ? val : b1[i]; // Prevent underflow by clamping
}
}
