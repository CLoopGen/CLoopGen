#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *scale;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer *indices = (integer*)malloc(i__1 * sizeof(integer));
for (integer j = 0; j < i__1; ++j) {
    indices[j] = j + 1;
}
for (integer j = 0; j < i__1; ++j) {
    scale[indices[j]] = 1.F;
}
free(indices);
}
