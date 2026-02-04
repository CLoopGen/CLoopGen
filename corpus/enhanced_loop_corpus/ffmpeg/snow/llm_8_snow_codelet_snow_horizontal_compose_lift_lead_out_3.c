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
    for (; i < w; i += 2) {
        dst[i] = src[i] - ((mul * (ref[i] + ref[i + 1]) + add) >> shift);
        if (i + 1 < w) {
            dst[i + 1] = src[i + 1] - ((mul * (ref[i + 1] + ref[i + 2]) + add) >> shift);
        }
    }
}
