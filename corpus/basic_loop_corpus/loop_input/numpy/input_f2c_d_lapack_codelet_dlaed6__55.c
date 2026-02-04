#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *d__ = NULL;
doublereal *z__ = NULL;
integer i__ = 0;
doublereal dscale[3];
doublereal zscale[3];

void init_vars() {
    d__ = (doublereal*)malloc(4 * sizeof(doublereal));
    z__ = (doublereal*)malloc(4 * sizeof(doublereal));

    for (int i = 1; i <= 3; ++i) {
        d__[i] = (doublereal)(i * 1.1);
        z__[i] = (doublereal)(i * 2.2);
    }
}