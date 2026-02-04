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
    for (i = 0; i < stereo * 2 + 1; i += 2) {
        *samples++ = pred[0] + i;
        if (i + 1 <= stereo) {
            *samples++ = pred[1] + i + 1;
        }
    }
}
