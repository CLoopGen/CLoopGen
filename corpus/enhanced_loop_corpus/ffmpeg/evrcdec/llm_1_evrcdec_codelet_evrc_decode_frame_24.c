#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 160; i += 4)
        for (int k = 0; k < 4 && (i + k) < 160; k++)
            samples[i + k] /= 32768;
}
