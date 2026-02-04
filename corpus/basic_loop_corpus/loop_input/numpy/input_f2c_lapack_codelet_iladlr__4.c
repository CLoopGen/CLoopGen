#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

const integer m_val = 1024;
const integer n_val = 1024;
const integer a_dim1 = 1024;
integer i__1;
integer ret_val;
integer i__;
integer j;

doublereal *a;
integer *m;

void init_vars() {
    m = (integer*)malloc(sizeof(integer));
    *m = m_val;
    i__1 = n_val;
    ret_val = 0;
    i__ = 0;
    j = 0;

    a = (doublereal*)calloc((m_val + 1) * (n_val + 1), sizeof(doublereal));

    for (integer col = 1; col <= n_val; ++col) {
        for (integer row = 1; row <= m_val; ++row) {
            if ((row + col) % 7 == 0) {
                a[row + col * a_dim1] = sin(row * 0.1) + cos(col * 0.1);
            }
        }
    }
}