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
    for (; !(lastv <= 0 || (v[i__].r != 0.F || v[i__].i != 0.F)); ) {
        i__1 = i__;
        --lastv;
        i__ -= *incv;
    }
}
