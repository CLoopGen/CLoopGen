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
    for (; i < w; i++) {
        if (ref[i] != 0) {
            dst[i] = src[i] + ((ref[i] + ref[(i + 1)] + 8 + 4 * src[i]) >> 4);
        } else {
            dst[i] = src[i];
        }
    }
}
