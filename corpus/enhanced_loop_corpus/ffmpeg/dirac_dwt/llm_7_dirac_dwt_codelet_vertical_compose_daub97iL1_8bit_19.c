#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *b0;
extern int16_t *b1;
extern int16_t *b2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (width > 0) {
    b1[0] = ((unsigned int)(b1[0]) - ((int)(1817 * (b0[0] + (unsigned int)b2[0]) + 2048) >> 12));
}
for (i = 1; i < width; i++) {
    int16_t prev_b0 = b0[i-1];
    int16_t current_sum = (unsigned int)(b0[i]) + (unsigned int)(b2[i]) + (unsigned int)(prev_b0);
    b1[i] = ((unsigned int)(b1[i]) - ((int)(1817 * current_sum + 2048) >> 12));
}
}
