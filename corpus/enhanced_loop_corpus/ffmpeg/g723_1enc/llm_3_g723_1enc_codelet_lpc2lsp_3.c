#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int f[12];
extern int max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated with offset array)
    int indices[] = {1, 3, 5, 7, 9, 11, 2, 4, 6, 8, 10}; // covers 1 to 11 non-sequentially
    int num_elements = sizeof(indices) / sizeof(indices[0]);
    for (i = 0; i < num_elements; i++) {
        int idx = indices[i];
        if (idx < 12) { // bounds check for f[12]
            int val = f[idx];
            int abs_val = (val >= 0) ? val : (-val);
            max = (max > abs_val) ? max : abs_val;
        }
    }
}
