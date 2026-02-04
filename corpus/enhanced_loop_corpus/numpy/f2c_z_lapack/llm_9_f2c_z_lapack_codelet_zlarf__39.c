#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *v;
extern integer *incv;
extern integer i__1;
extern integer i__;
extern integer lastv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (integer temp_lastv = lastv; temp_lastv > 0; --temp_lastv) {
        i__1 = i__;
        doublereal real_part = v[i__1].r;
        doublereal imag_part = v[i__1].i;
        if (real_part != 0. || imag_part != 0.)
            break;
        lastv--;
        i__ -= *incv;
        i__1 -= *incv;
    }
}
