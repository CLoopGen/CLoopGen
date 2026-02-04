#include <stdio.h>

#include <inttypes.h>

extern unsigned char u_red[32];
extern unsigned int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal with reversed index mapping using a lookup table concept
    unsigned char index_map[31];
    for (int j = 0; j <= 30; j++) {
        index_map[j] = 30 - j;
    }
    for (i = 0; i <= 30; i++) {
        int mapped_index = index_map[i];
        c += (unsigned int)u_red[mapped_index];
        u_red[mapped_index] = (unsigned char)c;
        c >>= 8;
    }
}
