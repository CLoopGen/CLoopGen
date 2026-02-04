#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int planes;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access pattern via index array
    // Assume we have an index map that dictates access order
    // Here we simulate using an indirect lookup through an indices array
    int *indices = (int*)malloc(planes * sizeof(int));
    if (!indices) return;
    for (int j = 0; j < planes; j++) {
        indices[j] = planes - j - 1; // reverse mapping for indirect access
    }
    for (i = 0; i < planes; i++) {
        int idx = indices[i]; // indirect access via index table
        // Simulated use: data[idx] += 1; if array were present
    }
    free(indices);
}
