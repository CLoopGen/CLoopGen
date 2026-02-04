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
    IDWTELEM acc = 0;
    for (; i < w; i++) {
        acc += src[i];
        dst[i] = acc + ((ref[i] + ref[(i + 1)] + 8 + 4 * acc) >> 4);
    }
}
