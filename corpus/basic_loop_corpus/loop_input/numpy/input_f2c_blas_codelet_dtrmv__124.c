#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef double doublereal;
typedef int logical;

integer *n;
doublereal *a;
doublereal *x;
integer a_dim1;
integer i__;
integer j;
doublereal temp;
logical nounit;

#define DATA_SIZE_MB 64

static doublereal *local_a = NULL;
static doublereal *local_x = NULL;
static integer local_n;

void init_vars() {
    local_n = (int)sqrt(DATA_SIZE_MB * 1024.0 * 1024.0 / (sizeof(doublereal) * 2));
    if (local_n < 10) local_n = 10;

    n = &local_n;
    a_dim1 = local_n;

    local_a = (doublereal*)calloc(local_n * local_n, sizeof(doublereal));
    local_x = (doublereal*)calloc(local_n, sizeof(doublereal));

    a = local_a;
    x = local_x;

    for (integer idx = 0; idx < local_n; ++idx) {
        x[idx] = 1.0 + 0.1 * idx;
        for (integer jdx = 0; jdx <= idx; ++jdx) {
            a[jdx + idx * a_dim1] = 0.1 * (1.0 + fabs(idx - jdx));
        }
    }

    nounit = 1;
    temp = 0.0;
    i__ = 0;
    j = 0;
}