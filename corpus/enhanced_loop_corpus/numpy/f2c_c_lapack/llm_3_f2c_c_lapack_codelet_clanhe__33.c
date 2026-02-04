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

typedef double doublereal;

extern singlecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern real r__1;
extern integer i__;
extern real sum;
extern real absa;
extern real scale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Strided memory access: traverse diagonal in reverse order with step of 1, starting from bottom-right
integer idx = i__1 * (a_dim1 + 1);
for (i__ = i__1; i__ >= 1; --i__, idx -= (a_dim1 + 1)) {
    if (a[idx].r != 0.F) {
        absa = (r__1 = a[idx].r, (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
        if (scale < absa) {
            r__1 = scale / absa;
            sum = sum * (r__1 * r__1) + 1.F;
            scale = absa;
        } else {
            r__1 = absa / scale;
            sum += r__1 * r__1;
        }
    }
}
}
