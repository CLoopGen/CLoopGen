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
extern integer i__2;
extern integer i__;
extern integer j;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access via Array Reindexing (row-major simulation)
    // Modify access pattern to a[] by transposing index usage to promote spatial locality
    for (j = 1; j <= i__1; ++j) {
        temp = x[j];
        if (nounit) {
            temp *= a[j * (a_dim1 + 1)]; // Access diagonal using flattened row-major pattern
        }
        i__2 = *n;
        for (i__ = j + 1; i__ <= i__2; ++i__) {
            temp += a[j * a_dim1 + i__] * x[i__]; // Stride by rows instead of columns
        }
        x[j] = temp;
    }
}
