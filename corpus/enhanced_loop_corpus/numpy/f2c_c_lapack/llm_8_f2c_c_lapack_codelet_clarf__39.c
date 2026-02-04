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
    i__1 = i__;
    for (; lastv > 0; --lastv, i__ -= *incv) {
        if (!(v[i__1].r == 0.F && v[i__1].i == 0.F))
            break;
        i__1 = i__ - *incv;
    }
}
