#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int fft_bits;
extern int w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (fft_bits = 1; (1 << fft_bits) < 2 * w; fft_bits += 1) {
        // Use an array with consecutive access pattern, simulating data-dependent indexing
        int path_index[16];
        // Consecutive write in reverse order as loop progresses
        int idx = 15 - (fft_bits % 16);
        if (idx >= 0) {
            path_index[idx] = 1 << fft_bits;
        }
    }
}
