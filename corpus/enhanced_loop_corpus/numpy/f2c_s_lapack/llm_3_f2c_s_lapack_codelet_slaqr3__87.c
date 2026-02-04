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
integer base;
for (j = 1; j <= i__1; ++j) {
    base = j * t_dim1;
    t[base + j + 2] = 0.F;
    t[base + j + 3] = 0.F;
}
}
