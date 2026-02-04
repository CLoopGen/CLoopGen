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

extern singlecomplex *beta;
extern singlecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride
    // Instead of accessing diagonal elements (i + i*lda), we access every second diagonal-like element
    // This creates a strided access pattern with stride (1 + a_dim1) * 2
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        if (i__ + i__ * a_dim1 <= i__1 * (a_dim1 + 1)) { // bounds check to stay within allocated range
            i__2 = i__ + i__ * a_dim1;
            a[i__2].r = beta->r;
            a[i__2].i = beta->i;
        }
    }
}
