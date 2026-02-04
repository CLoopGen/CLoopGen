#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *b0;
extern int32_t *b1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (width > 0) {
    for (i = 0; i < width; i += 2) {
        int end = (i + 1 < width) ? i + 2 : i + 1;
        for (int k = i; k < end; k++) {
            b0[k] = ((int)(b0[k] - (unsigned int)((int)(b1[k] + 1U) >> 1)));
            b1[k] = ((int)(b1[k] + (unsigned int)(b0[k])));
        }
    }
}
}
