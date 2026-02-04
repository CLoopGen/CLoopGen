#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int channel_id;
extern int64_t layout;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive array traversal simulating linear memory access pattern
    int shifts[64];
    int idx = 0;
    for (int temp = 32; temp > 0; temp >>= 1) {
        shifts[idx++] = temp;
    }
    // Traverse the precomputed shift values consecutively
    for (int pos = 0; pos < idx; pos++) {
        int i_val = shifts[pos];
        if (layout >= 1LL << i_val) {
            channel_id += i_val;
            layout >>= i_val;
        }
    }
}
