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
for (i = 0; i < w; i++) {
    if (i % 2 == 0 && i + 1 < w) {
        dst[i] = src[i] - ((mul * (ref[i] + ref[i + 1]) + add) >> shift);
        dst[i + 1] = src[i + 1] - ((mul * (ref[i + 1] + ref[i + 2]) + add) >> shift);
        i++;
    } else {
        dst[i] = src[i] - ((mul * (ref[i] + ref[i + 1]) + add) >> shift);
    }
}
}
