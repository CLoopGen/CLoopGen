#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *dest;
extern int dest_index;
extern int count;
extern int src_pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (unrolling-like pattern)
    // Accesses every second element first, then fills in the gaps
    int half_count = count / 2;
    for (i = 0; i < half_count; i++) {
        dest[dest_index + 2 * i] = dest[dest_index - src_pos + 2 * i];
    }
    for (i = 0; i < half_count; i++) {
        dest[dest_index + 2 * i + 1] = dest[dest_index - src_pos + 2 * i + 1];
    }
    // Handle odd count remainder
    if (count % 2 == 1) {
        dest[dest_index + count - 1] = dest[dest_index - src_pos + count - 1];
    }
}
