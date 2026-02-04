#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;
extern  uint8_t min_distance[2];
extern int16_t *quantizer_output;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 4; j++) {
    for (i = 1; i < 20; i++) {
        int diff = (quantizer_output[i - 1] - quantizer_output[i] + min_distance[j % 2]) >> 1;
        if (diff > 0) {
            quantizer_output[i - 1] -= diff;
            quantizer_output[i] += diff;
        }
    }
}
}
