#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int src_stride;
extern uint8_t *dst;
extern int dst_stride;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern with Pointer Arithmetic Unrolling
    // Use strided access across source and destination with manual unrolling for vectorization hints
    // Emphasize regular but non-consecutive strides to simulate optimized filter patterns

    uint8_t *s, *d;
    int ss = src_stride, ds = dst_stride * 3; // Flatten dst to row-major 3-element vectors

    for (i = 2; i < width - 2; i += 2) {
        s = src;
        d = dst;

        // Process two output rows at a time with explicit vertical offsets
        // Improve predictability of access pattern for compiler optimization

        // Top-left block: [0][0]
        d[0] = ((unsigned int)s[-ss + 0] + (unsigned int)s[+ss + 0]) >> 1;
        d[1] = s[0];
        d[2] = ((unsigned int)s[0 - 1] + (unsigned int)s[0 + 1]) >> 1;

        // Top-middle block: [0][1]
        d[ds + 0] = ((unsigned int)s[-ss + 0] + (unsigned int)s[-ss + 2] +
                     (unsigned int)s[+ss + 0] + (unsigned int)s[+ss + 2]) >> 2;
        d[ds + 1] = ((unsigned int)s[-ss + 1] + (unsigned int)s[0 + 0] +
                     (unsigned int)s[0 + 2] + (unsigned int)s[+ss + 1]) >> 2;
        d[ds + 2] = s[1];

        // Bottom-left block: [1][0]
        d[3 * ds + 0] = s[ss + 0];
        d[3 * ds + 1] = ((unsigned int)s[0 + 0] + (unsigned int)s[ss - 1] +
                         (unsigned int)s[ss + 1] + (unsigned int)s[2*ss + 0]) >> 2;
        d[3 * ds + 2] = ((unsigned int)s[0 - 1] + (unsigned int)s[0 + 1] +
                         (unsigned int)s[2*ss - 1] + (unsigned int)s[2*ss + 1]) >> 2;

        // Bottom-right block: [1][1]
        d[4 * ds + 0] = ((unsigned int)s[ss + 0] + (unsigned int)s[ss + 2]) >> 1;
        d[4 * ds + 1] = s[ss + 1];
        d[4 * ds + 2] = ((unsigned int)s[0 + 1] + (unsigned int)s[2*ss + 1]) >> 1;

        // Update pointers with fixed step
        src += 2;
        dst += 6;
    }
}
