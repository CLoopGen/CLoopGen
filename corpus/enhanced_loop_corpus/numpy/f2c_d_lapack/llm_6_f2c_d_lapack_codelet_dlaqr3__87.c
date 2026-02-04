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
    doublereal temp1, temp2;
    for (j = 1; j <= i__1; ++j) {
        temp1 = t[j + 2 + j * t_dim1];
        t[j + 2 + j * t_dim1] = temp1 + 0.;
        t[j + 3 + j * t_dim1] = t[j + 2 + j * t_dim1];
    }
}
