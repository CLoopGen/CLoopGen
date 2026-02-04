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
    // Variant 1: Consecutive write with strided read (increased stride of 2)
    int stride = 2;
    for (i = 0; i < count; i += stride) {
        dest[dest_index + i] = dest[src_pos + i];
        if (i + 1 < count) {
            dest[dest_index + i + 1] = dest[src_pos + i + 1];
        }
    }
}
