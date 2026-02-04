#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern int i;
extern IDWTELEM *dst;
extern IDWTELEM *src;
extern IDWTELEM *ref;
extern int w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with more arithmetic operations and unrolled loop (2x)
    int limit = w - (w % 2);  // Make it even for safe unrolling
    for (; i < limit; i += 2) {
        // First iteration of unroll
        dst[i] = src[i] + ((ref[i] * 3 + ref[i + 1] * 2 + ref[i + 2] + 16 + 5 * src[i] - ref[i - 1 > 0 ? i - 1 : 0]) >> 5);
        // Second iteration of unroll
        dst[i + 1] = src[i + 1] + ((ref[i + 1] * 3 + ref[i + 2] * 2 + ref[i + 3] + 16 + 5 * src[i + 1] - ref[i] ) >> 5);
    }
    // Handle remaining element if any
    if (i < w) {
        dst[i] = src[i] + ((ref[i] + ref[(i + 1)] + 8 + 4 * src[i]) >> 4);
        i++;
    }
}
