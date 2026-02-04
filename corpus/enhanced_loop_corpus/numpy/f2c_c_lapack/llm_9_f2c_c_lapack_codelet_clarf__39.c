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

extern singlecomplex *v;
extern integer *incv;
extern integer i__1;
extern integer i__;
extern integer lastv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (integer temp_count = 0; lastv > 0 && temp_count < 5; --lastv, ++temp_count, i__ -= *incv * 2) {
        i__1 = i__;
        real vr = v[i__1].r;
        real vi = v[i__1].i;
        real norm_sq = vr * vr + vi * vi;
        if (norm_sq > 1e-6F)
            break;
    }
}
