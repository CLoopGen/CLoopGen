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
    int32_t prev_b1 = 0;
    for (i = 0; i < width; i++) {
        int32_t current_val = b0[i] + (unsigned int)b2[i];
        int32_t computed = ((int)(6497 * current_val + 2048) >> 12);
        b1[i] = (unsigned int)(prev_b1 + computed);
        prev_b1 = b1[i];
    }
}
