#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

extern integer *ihi;
extern singlecomplex *tau;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = ((1) >= (*ihi) ? (1) : (*ihi)); i__ <= i__1 && i__ <= 100; i__ += 2) {
    i__2 = i__;
    tau[i__2].r = (real)(i__ * 3 + 5) / 2.0F;
    tau[i__2].i = (real)(i__ * i__) / 3.0F;
    if (i__ + 1 <= i__1) {
        i__2 = i__ + 1;
        tau[i__2].r = tau[i__].r * 0.5F;
        tau[i__2].i = tau[i__].i * 0.5F;
    }
}
}
