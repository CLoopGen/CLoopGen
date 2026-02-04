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
    // Variant 1: Consecutive memory access with loop unrolling by factor of 2
    // This improves spatial locality and reduces loop overhead
    int limit = x * y;
    int j;
    for (j = 0; j < limit; j += 2) {
        pointers_to_data[j] = data + (j * z);
        if (j + 1 < limit) {
            pointers_to_data[j + 1] = data + ((j + 1) * z);
        }
    }
}
