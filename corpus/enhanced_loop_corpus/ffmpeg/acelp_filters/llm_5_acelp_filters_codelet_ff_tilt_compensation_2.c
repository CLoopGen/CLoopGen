#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float tilt;
extern float *samples;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = size - 1; i > 0; i--) {
        if (i % 2 == 1) {
            samples[i] -= tilt * samples[i - 1];
        }
    }
}
