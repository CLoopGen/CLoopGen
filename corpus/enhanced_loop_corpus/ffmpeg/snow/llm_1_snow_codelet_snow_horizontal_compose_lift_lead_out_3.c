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
for (; i < w; i++) {
    int k = i;
    for (; k <= i; k++) {
        dst[k] = src[k] - ((mul * (ref[k] + ref[k + 1]) + add) >> shift);
    }
}
}
