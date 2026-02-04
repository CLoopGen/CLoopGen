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
    int offset = 0;
    for (i = 0; i < width; i++) {
        int temp_sum = b0[i] + b2[i] + 2;
        b1[i] -= (unsigned int)(temp_sum >> 2);
        if (i > 0) {
            b1[i] += (b1[i-1] & 0x3); // Introduce RAW dependency: current iteration reads previous b1 value
        }
    }
}
