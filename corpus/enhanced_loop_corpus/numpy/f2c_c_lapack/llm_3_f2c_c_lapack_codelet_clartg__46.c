#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

extern singlecomplex *r__;
extern integer i__1;
extern singlecomplex q__1;
extern integer i__;
extern real safmn2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 2
    // Process every second element in a strided pattern
    singlecomplex *base_r = r__;
    for (i__ = 0; i__ < i__1; i__ += 2) {
        q__1.r = safmn2 * base_r[i__].r;
        q__1.i = safmn2 * base_r[i__].i;
        base_r[i__].r = q__1.r;
        base_r[i__].i = q__1.i;
    }
}
