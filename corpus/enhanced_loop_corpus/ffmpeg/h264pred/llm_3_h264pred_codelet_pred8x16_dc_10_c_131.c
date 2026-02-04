#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern int dc2;
extern int dc3;
extern int dc4;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with unrolled-like indexing using array of offsets
    // Use a fixed offset array to simulate indirect access pattern with stride scaling
    const ptrdiff_t offsets[] = {
        -1,           // base offset for dc0 and dc2/dc3/dc4 terms
        0,            // for src[i - stride]
        4             // for src[4 + i - stride]
    };
    
    for (i = 0; i < 4; i++) {
        ptrdiff_t idx0 = offsets[0] + i * stride;
        ptrdiff_t idx1 = i - stride;
        ptrdiff_t idx2 = offsets[2] + i - stride;
        ptrdiff_t idx3 = offsets[0] + (i + 4) * stride;
        ptrdiff_t idx4 = offsets[0] + (i + 8) * stride;
        ptrdiff_t idx5 = offsets[0] + (i + 12) * stride;

        dc0 += src[idx0] + src[idx1];
        dc1 += src[idx2];
        dc2 += src[idx3];
        dc3 += src[idx4];
        dc4 += src[idx5];
    }
}
