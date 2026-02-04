#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned short *d;
extern int e;
extern int l;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    // Assume we have an auxiliary array 'indices' that stores reverse traversal indices
    // Since we can't introduce new globals, simulate indirect access with offset calculation
    int *indices = (int*)malloc(sizeof(int) * l);
    if (!indices) return; // Handle allocation failure
    for (int j = 0; j < l; ++j) {
        indices[j] = l - 1 - j; // Reverse order: l-1, l-2, ..., 0
    }
    for (i = 0; i < l; ++i, --e) {
        int idx = indices[i]; // Indirect access
        if (d[idx] != 0) {
            free(indices);
            return;
        }
    }
    free(indices);
}
