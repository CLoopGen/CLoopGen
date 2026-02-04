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
for (i = 0; i < width; i += 2) {
    if (i + 1 < width) {
        b2[i] = (int)(((unsigned int)(b2[i]) - ((int)(7U * b1[i] + 8U * b3[i] - b4[i] - b0[i] + 12) >> 4)));
        b2[i+1] = (int)(((unsigned int)(b2[i+1]) - ((int)(7U * b1[i+1] + 8U * b3[i+1] - b4[i+1] - b0[i+1] + 12) >> 4)));
    } else {
        b2[i] = (int)(((unsigned int)(b2[i]) - ((int)(7U * b1[i] + 8U * b3[i] - b4[i] - b0[i] + 12) >> 4)));
    }
}
}
