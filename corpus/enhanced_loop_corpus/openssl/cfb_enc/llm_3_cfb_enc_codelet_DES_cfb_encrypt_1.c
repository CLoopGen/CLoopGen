#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern int rem;
extern unsigned char *ovec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every second element in a shuffled pattern, still ensuring 8 writes
    for (i = 0; i < 8; ++i) {
        int src_offset = (i * 2) + num;  // Stride of 2 in source indexing
        ovec[i] = (ovec[src_offset] << rem) | (ovec[src_offset + 1] >> (8 - rem));
    }
}
