#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *sb_samples;
extern int *out_ptr;
extern int *buf;
extern int i;
extern int j;
extern int sblimit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with modified loop bounds and combined operations
    for (j = sblimit; j < 32; j++) {
        out_ptr = sb_samples + j;
        int limit = 9; // Half the original iterations, but process two values per iteration
        for (i = 0; i < limit; i++) {
            int base_idx = 8 * i;
            // Process two elements at once with fused store and zeroing logic
            out_ptr[0] = buf[base_idx];
            out_ptr[32] = buf[base_idx + 4];
            buf[base_idx] = buf[base_idx + 4] = 0;
            out_ptr += 64; // Advance by two steps of 32
        }
        // Adjust buf pointer using arithmetic instead of conditional
        buf += (j & 3) == 3 ? (4 * 18 - 3) : 1;
    }
}
