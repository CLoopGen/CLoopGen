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
    int16_t temp[2];
    for (i = 0; i <= stereo; i++) {
        temp[i] = pred[i];
        *samples++ = temp[i];
    }
}
