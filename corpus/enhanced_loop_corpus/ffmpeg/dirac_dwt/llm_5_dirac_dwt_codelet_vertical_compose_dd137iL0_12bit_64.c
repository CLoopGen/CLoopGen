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
    int temp = 9U * b1[i] + 9U * b3[i] - b4[i] - b0[i] + 16;
    if (temp > 32) {
        b2[i] = (int)(((unsigned int)(b2[i]) - (temp >> 5)));
    } else {
        b2[i] = b2[i]; // No change if condition not met
    }
}
}
