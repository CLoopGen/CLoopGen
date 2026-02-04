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
    int j;
    for (j = 0; j < w && i < w; j++, i++) {
        IDWTELEM s = src[i];
        IDWTELEM r1 = ref[i];
        IDWTELEM r2 = ref[i + 1];
        dst[i] = s + ((r1 + r2 + 8 + (s << 2)) >> 4);
    }
}
