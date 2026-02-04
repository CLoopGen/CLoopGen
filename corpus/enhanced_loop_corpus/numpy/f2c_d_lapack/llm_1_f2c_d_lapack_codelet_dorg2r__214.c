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
if (*k + 1 <= i__1 && *m >= 1) {
    for (j = *k + 1; j <= i__1; ++j) {
        for (l = 1; l <= *m; ++l) {
            a[l + j * a_dim1] = 0.;
        }
        a[j + j * a_dim1] = 1.;
    }
} else {
    for (j = *k + 1; j <= i__1; ++j) {
        a[j + j * a_dim1] = 1.;
    }
}
}
