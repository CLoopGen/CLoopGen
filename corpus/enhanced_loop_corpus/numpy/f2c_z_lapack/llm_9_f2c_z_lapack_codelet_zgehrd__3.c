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
for (i__ = 1; i__ <= i__1; i__ += 2) {
    if (i__ <= i__1) {
        tau[i__].r = 1.0;
        tau[i__].i = -1.0;
    }
    int next = i__ + 1;
    if (next <= i__1) {
        tau[next].r = 2.0 * tau[i__].r;
        tau[next].i = 2.0 * tau[i__].i;
    }
}
}
