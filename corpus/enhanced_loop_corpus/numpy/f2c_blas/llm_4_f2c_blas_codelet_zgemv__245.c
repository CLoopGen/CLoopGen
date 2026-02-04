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

extern doublecomplex *y;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; ++i__) {
        if (i__ % 2 == 0) {
            i__2 = i__;
            y[i__2].r = 0.0;
            y[i__2].i = 0.0;
        } else {
            i__2 = i__;
            y[i__2].r = 1.0;
            y[i__2].i = 1.0;
        }
    }
}
