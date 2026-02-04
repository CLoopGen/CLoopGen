#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int count;
extern int i;
extern int *recstart;
extern int *reclength;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    int *indices = (int*)malloc(count * sizeof(int));
    if (!indices) return;
    for (int k = 0; k < count; k++) {
        indices[k] = count - 1 - k; // reverse order access
    }
    for (i = 0; i < count; i++) {
        int idx = indices[i];
        recstart[idx] = 0;
        reclength[idx] = 0;
    }
    free(indices);
}
