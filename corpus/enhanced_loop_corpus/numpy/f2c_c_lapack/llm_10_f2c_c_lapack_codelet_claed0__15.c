#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *d__;
extern real *e;
extern integer *iwork;
extern integer i__1;
extern real r__1;
extern integer i__;
extern integer smm1;
extern integer submat;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 2; i__ <= i__1; i__ += 2) {
    integer idx1 = iwork[i__] + 1;
    integer sm1 = idx1 - 1;
    integer idx2 = iwork[i__-1] + 1;
    integer sm2 = idx2 - 1;
    real abs_e1 = (e[sm1] >= 0.0f) ? e[sm1] : -e[sm1];
    real abs_e2 = (e[sm2] >= 0.0f) ? e[sm2] : -e[sm2];
    d__[sm1] -= abs_e1;
    d__[idx1] -= abs_e1;
    d__[sm2] -= abs_e2;
    d__[idx2] -= abs_e2;
}
}
