#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *samples;
extern int i;
extern int stereo;
extern int pred[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i <= stereo; i++) {
        pred[i] += (pred[i] >> 4) + 1;
        for (j = 0; j < 3; j++) {
            pred[i] ^= (pred[i] << 3);
            pred[i] += i + 2;
        }
        *samples++ = pred[i];
    }
}
