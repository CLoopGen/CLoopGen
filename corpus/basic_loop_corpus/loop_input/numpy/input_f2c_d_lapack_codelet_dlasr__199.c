#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer *m;
integer *n;
doublereal *c__;
doublereal *s;
doublereal *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
doublereal temp;
doublereal ctemp;
doublereal stemp;

static doublereal *local_c;
static doublereal *local_s;
static doublereal *local_a;
static integer local_m_val;
static integer local_n_val;
static integer local_i1_val;

void init_vars() {
    local_m_val = 512;
    local_n_val = 512;
    local_i1_val = 256;
    a_dim1 = local_m_val;
    i__1 = local_i1_val;

    m = &local_m_val;
    n = &local_n_val;

    local_c = (doublereal*)calloc(local_i1_val + 1, sizeof(doublereal));
    local_s = (doublereal*)calloc(local_i1_val + 1, sizeof(doublereal));
    c__ = local_c;
    s = local_s;

    size_t a_size = (local_m_val + 1) * (local_n_val + 1);
    local_a = (doublereal*)calloc(a_size, sizeof(doublereal));
    a = local_a;

    for (int idx = 1; idx <= local_i1_val; ++idx) {
        double angle = idx * 0.01;
        local_c[idx] = cos(angle);
        local_s[idx] = sin(angle);
    }

    for (int i = 1; i <= local_m_val; ++i) {
        for (int j = 1; j <= local_n_val; ++j) {
            a[j + i * a_dim1] = (doublereal)(i + j);
        }
    }
}