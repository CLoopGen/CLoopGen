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
    for (i = 0; i < width; i++) {
        int temp_val = b1[i];
        b0[i] = ((int)(b0[i] - (unsigned int)((int)(temp_val + 1U) >> 1)));
        b1[i] = ((int)(temp_val + (unsigned int)(b0[i])));
    }
} else {
    for (i = 0; i < width; i++) {
        b0[i] = 0;
        b1[i] = 0;
    }
}
}
