#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int b0;
extern int b1;
extern int b2;
extern int16_t *b;
extern int16_t *temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Strided memory access with reversed traversal and offset indexing
    for (x = w2 - 1; x >= 1; x--) {
        int forward_offset = w2;
        int temp_idx_current = x;
        int temp_idx_next1 = x + forward_offset - 1;
        int temp_idx_next2 = x + forward_offset;

        // Access pattern now uses descending index with strided offsets
        b2 = ((unsigned int)(temp[temp_idx_current]) + 
              ((int)(217 * (temp[temp_idx_next1] + (unsigned int)temp[temp_idx_next2]) + 2048) >> 12));

        b1 = ((unsigned int)(temp[temp_idx_next1]) + 
              ((int)(6497 * (b0 + (unsigned int)b2) + 2048) >> 12));

        // Write to output array with precomputed strided indices in reverse order
        int write_idx_low = 2 * x - 1;
        int write_idx_high = 2 * x;

        b[write_idx_low] = ~((~b1) >> 1);
        b[write_idx_high] = ~((~b2) >> 1);

        b0 = b2;
    }
}
