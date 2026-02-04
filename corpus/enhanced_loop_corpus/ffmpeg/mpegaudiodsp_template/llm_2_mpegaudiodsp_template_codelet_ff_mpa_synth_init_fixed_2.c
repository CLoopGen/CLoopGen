#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t MPA_INT;

extern MPA_INT *window;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access, reorganize indexing to access memory sequentially
    // by precomputing base indices and using a single loop for better spatial locality
    
    MPA_INT *base_src, *base_dst;
    int offset;
    for (i = 0; i < 8; i++) {
        base_dst = &window[512 + 128 + 16 * i];
        base_src = &window[64 * i + 48];
        for (j = 0; j < 16; j++) {
            offset = 15 - j; // Reverse order locally to maintain correctness: 48-j becomes src[-j] => use offset from end
            base_dst[j] = base_src[-offset];
        }
    }
}
