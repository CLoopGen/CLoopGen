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
    IDWTELEM prev_temp = 0;
    for (; i < w; i++) {
        IDWTELEM temp = (mul * (ref[i] + ref[i + 1]) + add) >> shift;
        dst[i] = src[i] - temp - prev_temp;
        prev_temp = temp;
    }
}
