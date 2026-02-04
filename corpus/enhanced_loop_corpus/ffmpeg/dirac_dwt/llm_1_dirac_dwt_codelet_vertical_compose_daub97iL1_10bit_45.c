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
    for (i = 0; i < width; i += 2) {
        for (int k = 0; k < 2 && (i + k) < width; k++) {
            int idx = i + k;
            b1[idx] = ((unsigned int)(b1[idx]) - ((int)(1817 * (b0[idx] + (unsigned int)b2[idx]) + 2048) >> 12));
        }
    }
}
