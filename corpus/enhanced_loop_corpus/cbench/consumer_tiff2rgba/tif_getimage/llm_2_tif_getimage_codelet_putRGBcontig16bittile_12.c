#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef unsigned short uint16;

extern uint32 *cp;
extern uint32 x;
extern uint32 w;
extern int samplesperpixel;
extern uint16 *wp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pre-increment and unrolled access pattern (simulated)
    // Here, we change the access to wp to be more cache-friendly by accessing consecutive elements.
    // We assume samplesperpixel is known and fixed (e.g., 3 or 4), so we simulate direct indexing.
    uint32 count = w;
    for (x = 0; x < count; x++) {
        uint16 r = wp[0];
        uint16 g = wp[1];
        uint16 b = wp[2];
        *cp++ = ((uint32)((r >> 8) & 255)) | 
                ((uint32)((g >> 8) & 255) << 8) | 
                ((uint32)((b >> 8) & 255) << 16) | 
                ((uint32)(255UL << 24));
        wp += samplesperpixel;
    }
}
