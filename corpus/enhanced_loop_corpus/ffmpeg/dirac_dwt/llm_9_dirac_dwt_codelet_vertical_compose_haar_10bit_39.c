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
    int temp = b1[i] + 1U;
    b0[i] = b0[i] - (temp >> 1);
    for (j = 0; j < 2; j++) {
        b1[i] = b1[i] + (b0[i] >> j);
    }
}
}
