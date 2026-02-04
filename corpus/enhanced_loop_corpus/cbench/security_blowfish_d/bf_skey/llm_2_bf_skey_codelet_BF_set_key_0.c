#include <stdio.h>

#include <inttypes.h>

extern unsigned char *data;
extern int i;
extern unsigned long *p;
extern unsigned long ri;
extern unsigned char *d;
extern unsigned char *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pre-computed bounds and unrolled byte collection
    unsigned char *local_d = d;
    unsigned char *local_data = data;
    unsigned long *local_p = p;
    unsigned long local_ri;
    int local_i;

    for (local_i = 0; local_i < (16 + 2); local_i++) {
        local_ri = 0;
        // Read 4 bytes consecutively using pointer arithmetic without branching inside reads
        if (local_d + 3 < end) {
            local_ri = ((unsigned long)local_d[0] << 24) |
                       ((unsigned long)local_d[1] << 16) |
                       ((unsigned long)local_d[2] << 8)  |
                       ((unsigned long)local_d[3]);
            local_d += 4;
        } else {
            // Handle wraparound case byte by byte as in original
            local_ri = *(local_d++);
            if (local_d >= end) local_d = local_data;
            local_ri = (local_ri << 8) | *(local_d++);
            if (local_d >= end) local_d = local_data;
            local_ri = (local_ri << 8) | *(local_d++);
            if (local_d >= end) local_d = local_data;
            local_ri = (local_ri << 8) | *(local_d++);
            if (local_d >= end) local_d = local_data;
        }
        local_p[local_i] ^= local_ri;
    }

    // Update the global d to reflect the new position after processing
    d = local_d;
}
