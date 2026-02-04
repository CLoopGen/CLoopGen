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
int j;
for (i = 0; i < width; i++) {
    for (j = 0; j < 1; j++) {
        b0[i] = ((int)(b0[i] - (unsigned int)((int)(b1[i] + 1U) >> 1)));
        b1[i] = ((int)(b1[i] + (unsigned int)(b0[i])));
    }
}
}
