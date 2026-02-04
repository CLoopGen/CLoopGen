#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *distortion;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 64; i += 2) {
        distortion[i] = (1.0 - distortion[i]) * 0.5;
        if (i + 1 <= 64)
            distortion[i + 1] = (1.0 - distortion[i + 1]) * 0.5;
    }
}
