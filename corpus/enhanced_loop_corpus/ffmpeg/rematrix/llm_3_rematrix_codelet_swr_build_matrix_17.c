#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double matrix[18][18];
extern int64_t in_ch_layout;
extern int64_t out_ch_layout;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a precomputed index array to simulate irregular access pattern
    int indices[18];
    for (int temp_i = 0; temp_i < 18; temp_i++) {
        indices[temp_i] = temp_i; // Identity mapping for realism, but enables indirect access
    }
    for (i = 0; i < (sizeof (matrix) / sizeof ((matrix)[0])); i++) {
        int idx = indices[i]; // Simulate indirect access
        if (in_ch_layout & out_ch_layout & (1ULL << idx))
            matrix[idx][idx] = 1.;
    }
}
