#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef double doublereal;

extern integer *i0;
extern real *z__;
extern real *tau;
extern real *dmin__;
extern integer i__1;
extern real r__1;
extern real d__;
extern integer j4;
extern real emin;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with increased stride and prefetching pattern
    // Modify access to use a larger stride (8 instead of 4), processing every other original block
    // This changes data reuse pattern and may improve cache behavior for certain input sizes.
    integer step = 8;
    integer start = (*i0 << 2);
    // Align start to step if needed, though we assume valid input
    for (integer j4 = start; j4 <= i__1; j4 += step) {
        // Access same relative indices but skip every other iteration
        z__[j4 - 2] = d__ + z__[j4 - 1];
        temp = z__[j4 + 1] / z__[j4 - 2];
        d__ = d__ * temp - *tau;
        *dmin__ = (doublereal)((*dmin__) <= (d__) ? (*dmin__) : (d__));
        z__[j4] = z__[j4 - 1] * temp;
        r__1 = z__[j4];
        emin = (doublereal)((r__1) <= (emin) ? (r__1) : (emin));

        // Optional: unroll one instance of the original step within larger stride
        integer j4_inner = j4 + 4;
        if (j4_inner <= i__1) {
            z__[j4_inner - 2] = d__ + z__[j4_inner - 1];
            temp = z__[j4_inner + 1] / z__[j4_inner - 2];
            d__ = d__ * temp - *tau;
            *dmin__ = (doublereal)((*dmin__) <= (d__) ? (*dmin__) : (d__));
            z__[j4_inner] = z__[j4_inner - 1] * temp;
            r__1 = z__[j4_inner];
            emin = (doublereal)((r__1) <= (emin) ? (r__1) : (emin));
        }
    }
}
