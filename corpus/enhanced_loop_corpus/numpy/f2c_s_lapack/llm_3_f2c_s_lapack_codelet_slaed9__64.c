#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *k;
extern real *q;
extern real *dlamda;
extern real *w;
extern integer q_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
ptrdiff_t base_offset_w, base_offset_q, stride_q = q_dim1 * sizeof(real);
real *w_base = w;
real *q_base = q;
for (j = 1; j <= i__1; ++j) {
    i__2 = j - 1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        base_offset_w = i__;
        base_offset_q = i__ + j * q_dim1;
        w_base[base_offset_w] *= q_base[base_offset_q] / (dlamda[i__] - dlamda[j]);
    }
    i__2 = *k;
    for (i__ = j + 1; i__ <= i__2; ++i__) {
        base_offset_w = i__;
        base_offset_q = i__ + j * q_dim1;
        w_base[base_offset_w] *= q_base[base_offset_q] / (dlamda[i__] - dlamda[j]);
    }
}
}
