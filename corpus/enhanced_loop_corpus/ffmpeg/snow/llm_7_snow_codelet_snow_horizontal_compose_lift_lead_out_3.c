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
    IDWTELEM prev_ref = (i > 0) ? ref[i-1] : 0;
    for (; i < w; i++) {
        IDWTELEM sum = prev_ref + ref[i];
        dst[i] = src[i] - ((mul * sum + add) >> shift);
        prev_ref = ref[i+1]; 
    }
}
