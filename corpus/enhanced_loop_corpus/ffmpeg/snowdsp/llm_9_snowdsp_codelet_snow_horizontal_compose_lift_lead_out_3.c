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
    int stride = 4;
    for (; i <= w - stride; i += stride) {
        dst[i]     = src[i]     - ((mul * (ref[i]     + ref[i + 1])     + add) >> shift);
        dst[i + 1] = src[i + 1] - ((mul * (ref[i + 1] + ref[i + 2])   + add) >> shift);
        dst[i + 2] = src[i + 2] - ((mul * (ref[i + 2] + ref[i + 3])   + add) >> shift);
        dst[i + 3] = src[i + 3] - ((mul * (ref[i + 3] + ref[i + 4])   + add) >> shift);
    }
    // Handle remaining elements
    for (; i < w; i++) {
        dst[i] = src[i] - ((mul * (ref[i] + ref[i + 1]) + add) >> shift);
    }
}
