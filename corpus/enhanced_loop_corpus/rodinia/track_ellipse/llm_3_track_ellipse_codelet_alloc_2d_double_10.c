#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern double *data;
extern double **pointers;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing using an index array
    // Simulate indirect access pattern via stride multiplication (stride = 2)
    // Only valid indices are used, assuming x is within safe bounds
    int stride = 2;
    int limit = x * stride;
    if (limit > x) limit = x; // prevent overflow
    for (i = 0; i < x && (i * stride) < limit; i++) {
        int idx = (i * stride);
        pointers[i] = data + (idx * y);
    }
}
