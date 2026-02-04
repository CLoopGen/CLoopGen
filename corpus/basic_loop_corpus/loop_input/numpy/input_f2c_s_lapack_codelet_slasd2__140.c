#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *vt;
real *vt2;
integer vt_dim1;
integer vt2_dim1;
integer i__1;
real c__;
integer i__;
integer m;
real s;
integer nlp1;

static real vt_data[65536];
static real vt2_data[65536];

void init_vars() {
    const size_t data_size = 65536;
    const integer array_len = 256;

    vt_dim1 = array_len;
    vt2_dim1 = array_len;
    i__1 = 255;
    c__ = 1.5f;
    m = 0;
    s = 0.8f;
    nlp1 = 128;
    i__ = 0;

    vt = vt_data;
    vt2 = vt2_data;
}