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
    IDWTELEM temp;
    for (; i < w; i++) {
        temp = (ref[i] + ref[i + 1]);
        dst[i] = src[i] - ((mul * temp + add) >> shift);
    }
}
