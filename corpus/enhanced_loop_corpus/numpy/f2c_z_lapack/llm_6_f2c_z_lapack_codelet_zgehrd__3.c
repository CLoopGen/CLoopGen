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
        tau[i__].r = 0.0;
        tau[i__].i = 0.0;
        if (i__ > 1) {
            tau[i__].r += tau[i__ - 1].r; // Introduce RAW dependency: current depends on previous
        }
    }
}
