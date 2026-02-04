#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *work;
extern integer i__1;
extern real r__1;
extern real r__2;
extern integer i__;
extern real value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer *indices = (integer*)malloc(i__1 * sizeof(integer));
for (integer j = 0; j < i__1; ++j) {
    indices[j] = j + 1;
}
for (i__ = 0; i__ < i__1; ++i__) {
    integer idx = indices[i__];
    r__1 = value;
    r__2 = work[idx];
    value = (doublereal)((r__1) >= (r__2) ? (r__1) : (r__2));
}
free(indices);
}
