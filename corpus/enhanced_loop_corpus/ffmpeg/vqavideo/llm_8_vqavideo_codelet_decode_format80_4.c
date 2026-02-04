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
    int limit = count & (~3); // Round down to multiple of 4 for unrolling
    for (i = 0; i < limit; i += 4) {
        dest[dest_index + i]     = dest[dest_index - src_pos + i];
        dest[dest_index + i + 1] = dest[dest_index - src_pos + i + 1];
        dest[dest_index + i + 2] = dest[dest_index - src_pos + i + 2];
        dest[dest_index + i + 3] = dest[dest_index - src_pos + i + 3];
    }
    // Handle remaining elements
    for (; i < count; i++)
        dest[dest_index + i] = dest[dest_index - src_pos + i];
}
