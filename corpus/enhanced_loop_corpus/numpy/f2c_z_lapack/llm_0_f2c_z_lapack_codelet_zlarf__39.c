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
    for (; lastv > 0; --lastv) {
        i__1 = i__;
        if (!(v[i__1].r == 0. && v[i__1].i == 0.))
            break;
        i__ -= *incv;
    }
}
