#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *d__;
extern real *e;
extern integer *iwork;
extern integer i__1;
extern real r__1;
extern integer i__;
extern integer smm1;
extern integer submat;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer *indices = iwork + 1;
real *d_ptr = d__;
real *e_ptr = e;
for (i__ = 1; i__ <= i__1; ++i__) {
    integer base_offset = indices[i__];
    submat = base_offset + 1;
    smm1 = base_offset;
    d_ptr[smm1] -= (r__1 = e_ptr[smm1], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
    d_ptr[submat] -= (r__1 = e_ptr[smm1], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
}
}
