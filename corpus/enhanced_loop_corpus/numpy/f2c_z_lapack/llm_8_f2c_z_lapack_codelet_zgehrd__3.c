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

extern doublecomplex *tau;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    for (int j = 0; j < 4; ++j) {
        tau[i__].r += (doublereal)(j * i__) / 2.5;
        tau[i__].i -= (doublereal)(j * i__) / 3.7;
    }
}
}
