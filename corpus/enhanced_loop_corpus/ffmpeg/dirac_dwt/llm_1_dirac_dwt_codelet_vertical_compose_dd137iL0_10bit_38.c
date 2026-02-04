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
        for (int k = i; k < i + 4 && k < width; k++) {
            b2[k] = (int)(((unsigned int)(b2[k]) - ((int)(9U * b1[k] + 9U * b3[k] - b4[k] - b0[k] + 16) >> 5)));
        }
    }
}
