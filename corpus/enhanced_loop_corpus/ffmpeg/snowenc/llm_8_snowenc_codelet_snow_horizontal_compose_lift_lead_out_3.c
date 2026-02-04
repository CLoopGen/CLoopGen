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
for (j = 0; j < w && i < w; j++, i++) {
    IDWTELEM temp1 = ref[i] + ref[i + 1];
    IDWTELEM temp2 = mul * temp1;
    IDWTELEM temp3 = temp2 + add;
    dst[i] = src[i] - (temp3 >> shift);
}
}
