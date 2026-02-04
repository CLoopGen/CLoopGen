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
    // Variant 2: Indirect Memory Access via Index Array
    // Use an index array to control access into buf and sb_samples indirectly.
    // This simulates irregular or table-driven access patterns.
    static const int index_map[18] = {0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68}; // 4*i for i=0..17
    int out_index[18];
    for (i = 0; i < 18; i++) {
        out_index[i] = i * 32;
    }
    for (j = sblimit; j < 32; j++) {
        int base_offset = j;
        for (i = 0; i < 18; i++) {
            int b_idx = index_map[i];
            int o_idx = out_index[i];
            (sb_samples + base_offset)[o_idx] = buf[b_idx];
            buf[b_idx] = 0;
        }
        buf += (j & 3) != 3 ? 1 : (4 * 18 - 3);
    }
}
