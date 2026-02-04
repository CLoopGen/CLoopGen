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
extern int mul;
extern int add;
extern int shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive two-element unrolling with forward sequential access
    // This variant accesses memory in consecutive pairs, unrolling the loop body
    // to process two elements per iteration, improving spatial locality.
    int limit = w - 1;
    for (; i < limit; i += 2) {
        dst[i]     = src[i]     - ((mul * (ref[i]     + ref[i + 1])     + add) >> shift);
        dst[i + 1] = src[i + 1] - ((mul * (ref[i + 1] + ref[i + 2])     + add) >> shift);
    }
    // Handle remaining element if w is odd
    if (i == w - 1) {
        dst[i] = src[i] - ((mul * (ref[i] + ref[i + 1]) + add) >> shift);
        i++;
    }
}
