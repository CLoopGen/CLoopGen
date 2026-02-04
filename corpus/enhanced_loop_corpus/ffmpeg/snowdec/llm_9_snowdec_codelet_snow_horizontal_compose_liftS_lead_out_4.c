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
    int stride = 2;
    for (; i < w - 1; i += stride) {
        dst[i]     = src[i] + ((ref[i] + ref[i + 1] + 8 + 4 * src[i]) >> 4);
        dst[i + 1] = src[i + 1] + ((ref[i + 1] + ref[i + 2] + 8 + 4 * src[i + 1]) >> 4);
    }
    // Handle remaining element if w is odd
    if (i == w - 1) {
        dst[i] = src[i] + ((ref[i] + ref[i + 1] + 8 + 4 * src[i]) >> 4);
    }
}
