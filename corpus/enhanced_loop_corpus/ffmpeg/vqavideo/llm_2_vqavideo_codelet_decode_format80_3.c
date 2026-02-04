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
    // Variant 1: Consecutive memory access with forward iteration (unrolled by 2)
    int limit = count - 1;
    for (i = 0; i < limit; i += 2) {
        dest[dest_index + i]     = dest[src_pos + i];
        dest[dest_index + i + 1] = dest[src_pos + i + 1];
    }
    // Handle remaining element if count is odd
    if (i < count) {
        dest[dest_index + i] = dest[src_pos + i];
    }
}
