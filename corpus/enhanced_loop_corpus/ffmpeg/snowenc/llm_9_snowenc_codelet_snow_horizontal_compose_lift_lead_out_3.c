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
int step = 2;
for (; i < w - 1; i += step) {
    IDWTELEM val1 = ((mul * (ref[i] + ref[i + 1]) + add) >> shift);
    IDWTELEM val2 = ((mul * (ref[i+1] + ref[i + 2]) + add) >> shift);
    dst[i] = src[i] - val1;
    dst[i+1] = src[i+1] - val2;
}
if (i == w - 1) {
    dst[i] = src[i] - ((mul * (ref[i] + ref[i + 1]) + add) >> shift);
}
}
