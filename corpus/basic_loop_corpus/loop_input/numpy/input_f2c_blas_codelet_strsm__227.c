#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;
typedef int logical;

integer n_data = 512;
integer m_data = 512;
real alpha_data = 0.8f;

integer *m = &m_data;
integer *n = &n_data;
real *alpha = &alpha_data;

real a_data[512 * 512];
real b_data[512 * 512];

real *a = a_data;
real *b = b_data;

integer a_dim1 = 512;
integer b_dim1 = 512;

integer i__1;
integer i__2;
integer i__;
integer j;
integer k;
real temp;
logical nounit = 1;

void init_vars() {
    for (int idx = 0; idx < 512 * 512; ++idx) {
        a_data[idx] = (real)(rand() % 100) / 10.0f + 1.0f;
        b_data[idx] = (real)(rand() % 100) / 10.0f;
    }
    
    for (int i = 0; i < 512; ++i) {
        for (int j = 0; j < 512; ++j) {
            if (i == j) {
                a_data[i + j * a_dim1] = (real)(rand() % 100) / 10.0f + 2.0f;
            }
        }
    }

    nounit = 1;
    temp = 0.0f;
    i__ = 0;
    j = 0;
    k = 0;
    i__1 = 0;
    i__2 = 0;
}