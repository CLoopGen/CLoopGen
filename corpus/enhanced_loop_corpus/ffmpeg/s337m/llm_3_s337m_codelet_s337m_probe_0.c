#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int markers[3];
extern int i;
extern int sum;
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulating gather access)
    int n = sizeof(markers) / sizeof(markers[0]);
    int indices[3];
    for (i = 0; i < n; i++) {
        indices[i] = i; // Populate index map (could be randomized or reordered in real use cases)
    }
    // Use indirect access via indices
    for (i = 0; i < n; i++) {
        int idx = indices[i]; // Indirect addressing
        sum += markers[idx];
        if (markers[max] < markers[idx])
            max = idx;
    }
}
