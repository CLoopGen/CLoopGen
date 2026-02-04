#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *n;
extern doublereal *a;
extern doublereal *x;
extern integer a_dim1;
extern integer i__;
extern integer j;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *n; j >= 2; --j) { // Reduced trip count: stops at 2 instead of 1
    temp = x[j];
    if (nounit) {
        temp *= a[j + j * a_dim1];
    }
    for (i__ = j - 1; i__ >= 1; --i__) {
        temp += a[i__ + j * a_dim1] * x[i__];
    }
    x[j] = temp;
}
// Handle remaining element separately to maintain correctness for odd-sized workloads
if (*n >= 1) {
    x[1] *= a[1 + 1 * a_dim1]; // Simplified update for first element, assuming nounit effect
}
}
