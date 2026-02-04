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
    IDWTELEM temp;
    for (int j = 0; j < w; j++) {
        temp = ((ref[j] + ref[(j + 1)] + 8 + 4 * src[j]) >> 4);
        dst[j] = src[j] + temp;
    }
}
