#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *t;
extern integer t_dim1;
extern integer i__1;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    if (j + 1 <= i__1) {
        t[j + 2 + j * t_dim1] = 0.;
        t[j + 3 + j * t_dim1] = 0.;
        t[j + 1 + 2 + (j + 1) * t_dim1] = 0.;
        t[j + 1 + 3 + (j + 1) * t_dim1] = 0.;
    } else {
        t[j + 2 + j * t_dim1] = 0.;
        t[j + 3 + j * t_dim1] = 0.;
    }
}
}
