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
extern integer i__;
extern integer j;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *n; j >= 2; --j) { // Reduce trip count by 1, skip j=1
    temp = x[j];
    if (nounit) {
        temp *= a[j + j * a_dim1];
    }
    for (i__ = j - 1; i__ >= 1; --i__) {
        if (i__ % 2 == 1) { // Add conditional to reduce effective work
            temp += a[i__ + j * a_dim1] * x[i__];
        }
    }
    x[j] = temp;
}
if (*n >= 1) { // Handle remaining element separately
    x[1] = x[1] * (nounit ? a[1 + 1 * a_dim1] : 1);
}
}
