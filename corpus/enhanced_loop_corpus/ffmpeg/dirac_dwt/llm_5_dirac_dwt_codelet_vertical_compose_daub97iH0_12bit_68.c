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
    for (i = 0; i < width; i++) {
        int32_t temp_sum = b0[i] + (unsigned int)b2[i];
        if (temp_sum < 1000) {
            b1[i] = ((unsigned int)(b1[i]) + ((int)(6497 * temp_sum + 2048) >> 12));
        } else {
            b1[i] = b1[i]; // No change in b1[i] for large sums
        }
    }
}
