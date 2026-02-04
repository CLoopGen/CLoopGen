#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int DWTELEM;

extern DWTELEM *dst;
extern DWTELEM *src;
extern DWTELEM *ref;
extern int dst_step;
extern int src_step;
extern int ref_step;
extern int mul;
extern int add;
extern int shift;
extern int inverse;
extern  int w;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Pointer Arithmetic
    DWTELEM *d = dst;
    DWTELEM *s = src;
    DWTELEM *r = ref;
    for (i = 0; i < w; i++) {
        d[i] = ((inverse) 
                ? s[i] + ((mul * (r[i] + r[i + 1]) + add) + 4 * s[i] >> shift)
                : -((-16 * s[i] + (mul * (r[i] + r[i + 1]) + add) + add / 4 + 1 + (5 << 25)) / (5 * 4) - (1 << 23)));
    }
}
