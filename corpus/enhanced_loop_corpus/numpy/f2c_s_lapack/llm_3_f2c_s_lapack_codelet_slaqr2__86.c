#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *t;
extern integer t_dim1;
extern integer i__1;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    int idx1 = j + j * t_dim1 + 2;
    int idx2 = j + j * t_dim1 + 3;
    t[idx1] = 0.F;
    t[idx2] = 0.F;
}
}
