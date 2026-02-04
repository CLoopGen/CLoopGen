#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern int z;
extern double *data;
extern double **pointers_to_data;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int trip_count = x * y * z;
    for (i = 0; i < trip_count; i++) {
        int idx = i / z;
        pointers_to_data[idx] = data + (idx * z);
    }
}
