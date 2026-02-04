#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int frequency[512];
extern uint8_t flag[512];
extern int up[512];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access via Array Restructuring (AoS to SoA-like access pattern)
    // Instead of accessing frequency[i], flag[i], up[i] non-consecutively in inner loop,
    // we reorganize the access to improve spatial locality by processing elements sequentially.
    for (j = 257; j < 512; j++) {
        int min_freq[2] = {256 * 256, 256 * 256};
        int smallest[2] = {0, 0};

        // First pass: sequential scan with consecutive memory reads from frequency[]
        for (int i = 0; i < j; i++) {
            int freq_val = frequency[i];
            if (freq_val == 0) continue;

            if (freq_val < min_freq[0]) {
                min_freq[1] = min_freq[0];
                smallest[1] = smallest[0];
                min_freq[0] = freq_val;
                smallest[0] = i;
            } else if (freq_val < min_freq[1]) {
                min_freq[1] = freq_val;
                smallest[1] = i;
            }
        }

        if (min_freq[1] == 256 * 256)
            break;

        // Update using direct assignments with coalesced stores
        frequency[j] = min_freq[0] + min_freq[1];

        uint8_t* flag_ptr = &flag[smallest[0]];
        int* up_ptr = &up[smallest[0]];
        flag_ptr[0] = 0;
        flag_ptr[1] = 1;
        up_ptr[0] = j;
        up_ptr[1] = j;

        frequency[smallest[0]] = 0;
        frequency[smallest[1]] = 0;
    }
}
