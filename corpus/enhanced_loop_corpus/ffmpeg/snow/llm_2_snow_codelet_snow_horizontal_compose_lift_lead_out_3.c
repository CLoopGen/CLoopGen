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
    // Variant 1: Strided memory access (stride of 2) - processes every second element
    for (; i < w; i += 2) {
        if (i + 1 < w) {  // Ensure ref[i+1] is safe to access
            dst[i] = src[i] - ((mul * (ref[i] + ref[i + 1]) + add) >> shift);
        } else {
            // Handle edge case when i is the last element
            dst[i] = src[i] - ((mul * (ref[i] + ref[i]) + add) >> shift);
        }
    }
}
