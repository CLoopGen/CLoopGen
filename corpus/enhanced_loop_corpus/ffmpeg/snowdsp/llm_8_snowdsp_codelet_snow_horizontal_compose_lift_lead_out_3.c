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
    int j;
    for (j = 0; j < w * 2; j += 2) {
        if (i >= w) break;
        IDWTELEM val1 = ref[i] + ref[i + 1];
        IDWTELEM val2 = mul * val1 + add;
        dst[i] = src[i] - (val2 >> shift);
        i++;
        if (i >= w) break;
        val1 = ref[i] + ref[i + 1];
        val2 = mul * val1 + add;
        dst[i] = src[i] - (val2 >> shift);
        i++;
    }
}
