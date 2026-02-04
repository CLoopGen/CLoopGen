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
    for (i = 0; i < width; i += 4) {
        for (int k = 0; k < 4 && (i + k) < width; k++) {
            int idx = i + k;
            b2[idx] = (int)(((unsigned int)(b2[idx]) - ((int)(9U * b1[idx] + 9U * b3[idx] - b4[idx] - b0[idx] + 16) >> 5)));
        }
    }
}
