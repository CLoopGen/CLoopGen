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
    // Variant 2: Reverse consecutive access from the end
    // Iterates backward through the arrays
    for (; i >= 0 && (w - 1 - i) >= 0; i++) {
        int idx = w - 1 - i;
        dst[idx] = src[idx] + ((ref[idx] + ref[idx + 1 < w ? idx + 1 : idx] + 8 + 4 * src[idx]) >> 4);
    }
}
