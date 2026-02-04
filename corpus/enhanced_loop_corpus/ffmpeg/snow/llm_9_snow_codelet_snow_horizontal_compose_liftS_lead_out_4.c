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
    for (; i < w && i < 64; i++) {
        IDWTELEM r = ref[i];
        IDWTELEM s = src[i];
        dst[i] = s + ((r + ref[(i + 1)] + 8 + (s << 2)) >> 4);
    }
}
