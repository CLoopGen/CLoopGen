#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int markers[64];
extern int sum;
extern int max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (reverse order traversal)
    int n = sizeof(markers) / sizeof(markers[0]);
    int indices[64];
    for (int j = 0; j < n; j++) {
        indices[j] = n - 1 - j;  // Reverse indexing
    }
    for (i = 0; i < n; i++) {
        int idx = indices[i];
        sum += markers[idx];
        if (markers[max] < markers[idx])
            max = idx;
    }
}
