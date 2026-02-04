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
    int32_t temp_b1 = b1[i];
    int32_t temp_b0 = b0[i] - ((temp_b1 + 1U) >> 1);
    b0[i] = temp_b0;
    for (j = 0; j < 3; j++) {
        temp_b1 += temp_b0;
    }
    b1[i] = temp_b1;
}
}
