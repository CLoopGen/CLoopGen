#include <stdio.h>

#include <inttypes.h>

extern int dfa_p[7056];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via simple arithmetic)
    int indices[4 * 21 * 4 * 21];
    for (int temp_idx = 0; temp_idx < 4 * 21 * 4 * 21; temp_idx++) {
        indices[temp_idx] = temp_idx;
    }
    for (int idx = 0; idx < 4 * 21 * 4 * 21; idx++) {
        int i = indices[idx]; // Simulate indirect access
        dfa_p[i] = 3;
    }
}
