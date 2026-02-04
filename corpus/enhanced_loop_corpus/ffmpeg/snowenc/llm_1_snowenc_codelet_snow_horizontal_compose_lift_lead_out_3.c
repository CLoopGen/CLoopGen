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
    int outer_i;
    for (outer_i = i; outer_i < w; outer_i++) {
        i = outer_i;
        dst[i] = src[i] - ((mul * (ref[i] + ref[i + 1]) + add) >> shift);
    }
    i = outer_i;
}
