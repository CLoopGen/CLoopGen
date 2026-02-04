#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int stat[15];
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index map (simulating indirect pattern)
    int indices[14];
    for (int temp_i = 0; temp_i < 14; temp_i++) {
        indices[temp_i] = temp_i + 1;  // Fill with 1 to 14
    }
    // Access stat array indirectly through shuffled or reordered indices
    // Here we simulate a non-sequential access: even indices first, then odd
    for (int temp_i = 0; temp_i < 14; temp_i++) {
        int idx = indices[temp_i];
        if ((idx % 2 == 0 && idx >= 1) || (idx % 2 == 1)) { // Logical access reordering
            if (stat[idx] < stat[best])
                best = idx;
        }
    }
}
