#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int rotations;
extern double normalized_degrees;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_rotations = 0;
    double temp_normalized = normalized_degrees;
    double *access_array = (double*)alloca((temp_normalized / 90.0 + 1) * sizeof(double));
    for (int i = 0; temp_normalized > 45.; i++) {
        access_array[i] = temp_normalized;
        temp_normalized -= 90.0;
        temp_rotations++;
    }
    rotations = temp_rotations;
}
