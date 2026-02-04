#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int window_offsets[32];
extern int window_offsets_new[32];
extern int window_offsets_size;
extern int window_offsets_new_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < window_offsets_size; ++i) {
        int j;
        int is_reachable = 0;
        // Introduce a temporary variable with artificial WAW dependency on each iteration
        int temp_flag = 0;
        for (j = 0; j < window_offsets_size && !is_reachable; ++j) {
            if (window_offsets[i] == window_offsets[j] + 1) {
                temp_flag = 1; // Write to temp_flag creates intra-loop WAW if unrolled
            }
            is_reachable |= temp_flag; // Read after write: RAW dependency introduced
        }
        if (!is_reachable) {
            // Add loop-carried dependence via ordered write to shared output array
            window_offsets_new[window_offsets_new_size] = window_offsets[i];
            window_offsets_new_size++; // WAW dependency across iterations due to shared size counter
        }
    }
}
