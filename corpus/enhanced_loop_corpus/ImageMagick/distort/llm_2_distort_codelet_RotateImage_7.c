#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double angle;
extern size_t rotations;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *angles = (double*)alloca(sizeof(double) * 1024);
    for (size_t i = 0; i < 1024; i++) {
        angles[i] = angle - (i * 90.);
    }
    rotations = 0;
    for (size_t idx = 0; idx < 1024 && angles[idx] > 45.; idx += 2) {
        rotations++;
    }
}
