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
    int step = 2;
    int adjusted_count = (count + 1) / step; // Reduce effective trip count with larger step
    for (i = 0; i < adjusted_count; i++) {
        int offset = dest_index + i * step;
        int src_offset = dest_index - src_pos + i * step;
        dest[offset] = dest[src_offset];
        if (i * step + 1 < count)
            dest[offset + 1] = dest[src_offset + 1];
    }
}
