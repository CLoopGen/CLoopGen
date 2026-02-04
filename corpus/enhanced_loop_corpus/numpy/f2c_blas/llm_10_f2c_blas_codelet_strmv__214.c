#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *n;
extern real *a;
extern real *x;
extern integer a_dim1;
extern integer i__1;
extern integer i__;
extern integer j;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *n; j >= 2; --j) { // Reduced trip count by starting effective work from n down to 2
    if (x[j] != 0.F && x[j-1] != 0.F) { // Increased condition complexity
        temp = x[j] + x[j-1]; // Combined values to increase computational intensity
        i__1 = j + 1;
        for (i__ = *n; i__ >= i__1; --i__) {
            real coeff = a[i__ + j * a_dim1];
            x[i__] += temp * coeff; // One multiplication and addition
            x[i__] += coeff * coeff; // Extra arithmetic operation to increase computation per memory access
        }
        if (nounit) {
            x[j] *= a[j + j * a_dim1];
            x[j-1] *= a[j-1 + (j-1) * a_dim1];
        }
    }
}
}
