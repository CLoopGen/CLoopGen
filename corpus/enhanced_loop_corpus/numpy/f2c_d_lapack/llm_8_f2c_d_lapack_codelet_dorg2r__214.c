#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern integer *k;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer j;
extern integer l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *k + 1; j <= i__1; ++j) {
    i__2 = *m;
    for (l = 1; l <= i__2; ++l) {
        if (l != j) {
            a[l + j * a_dim1] = (doublereal)(l % 2) ? -0.5 : 0.5;
        } else {
            a[l + j * a_dim1] = 1.0;
        }
    }
}
}
