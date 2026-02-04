#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t FFTSample;

extern int m;
extern FFTSample *tab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    // We simulate indirect access by creating a lookup pattern: j = i
    // This models potential future extension with non-linear indexing
    int *indices = (int*)malloc((m / 4) * sizeof(int));
    if (!indices) return; // Handle malloc failure
    for (int i = 0; i < m / 4; i++) {
        indices[i] = i + 1;
    }
    for (int k = 0; k < m / 4; k++) {
        int i = indices[k];
        tab[m / 2 - i] = tab[i];
    }
    free(indices);
}
