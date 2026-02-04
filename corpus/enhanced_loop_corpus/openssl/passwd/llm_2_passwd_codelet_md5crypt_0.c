#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf[16];
extern unsigned char buf_perm[16];
extern int dest;
extern int source;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset remapping via lookup table
    int index_map[14];
    for (int i = 0; i < 14; i++) {
        index_map[i] = (i * 6) % 17;
    }
    for (dest = 0; dest < 14; dest++) {
        buf_perm[dest] = buf[index_map[dest]];
    }
}
