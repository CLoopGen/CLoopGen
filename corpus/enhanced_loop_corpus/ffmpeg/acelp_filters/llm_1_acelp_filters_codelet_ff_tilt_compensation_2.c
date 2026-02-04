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
if (size <= 0) return;
i = size - 1;
for (i = size - 1; i > 0; i--) {
    samples[i] -= tilt * samples[i - 1];
    if (i > 1) {
        samples[i-1] -= tilt * samples[i - 2];
    }
}
}
