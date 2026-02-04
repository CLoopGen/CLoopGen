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
    int16_t *restrict r_b0 = b0;
    int16_t *restrict r_b1 = b1;
    int16_t *restrict r_b2 = b2;
    int acc = 0;
    for (i = 0; i < width; i++) {
        acc += (r_b0[i] + r_b2[i]); // Introduce loop-carried dependency (WAW and RAW on acc)
        r_b1[i] = (int16_t)((unsigned int)r_b1[i] + ((6497 * (r_b0[i] + r_b2[i]) + 2048) >> 12));
    }
    // Use acc to prevent elimination (e.g., via volatile side effect simulation)
    if (acc < 0) {
        r_b1[0] = (int16_t)(acc & 0xFFFF);
    }
}
