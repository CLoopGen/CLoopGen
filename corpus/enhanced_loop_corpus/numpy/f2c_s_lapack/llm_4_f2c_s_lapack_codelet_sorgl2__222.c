#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern integer *k;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer j;
extern integer l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    for (l = *k + 1; l <= i__2; ++l) {
        if (l != j || j <= *k) {
            a[l + j * a_dim1] = 0.F;
        }
    }
    if (j > *k && j <= *m) {
        a[j + j * a_dim1] = 1.F;
    }
}
}
