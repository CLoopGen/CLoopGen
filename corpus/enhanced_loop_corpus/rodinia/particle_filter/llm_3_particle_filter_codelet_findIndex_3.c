#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *CDF;
extern int lengthCDF;
extern double value;
extern int _usr_index;
extern int x;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 2: Indirect memory access using an index array
    // Simulate indirect access via precomputed indices (e.g., reverse order access)
    int *indices = (int*)malloc(lengthCDF * sizeof(int));
    for (int i = 0; i < lengthCDF; i++) {
        indices[i] = lengthCDF - 1 - i; // Reverse order traversal
    }

    index = -1;
    for (x = 0; x < lengthCDF; x++) {
        int pos = indices[x]; // Indirect access through index mapping
        if (CDF[pos] >= value) {
            index = pos;
            break;
        }
    }

    free(indices);
}
