#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;

real *d__ = NULL;
real *z__ = NULL;
real *dlamda = NULL;
real *w = NULL;
integer *indx = NULL;
integer i__1 = 0;
integer i__ = 0;

void init_vars() {
    const size_t data_size = (1 << 20); // ~4MB total, gives ample work (~1M iterations)
    i__1 = (integer)data_size;

    d__ = (real*)calloc(data_size + 1, sizeof(real));
    z__ = (real*)calloc(data_size + 1, sizeof(real));
    dlamda = (real*)malloc((data_size + 1) * sizeof(real));
    w = (real*)malloc((data_size + 1) * sizeof(real));
    indx = (integer*)malloc((data_size + 1) * sizeof(integer));

    if (!d__ || !z__ || !dlamda || !w || !indx) {
        exit(1);
    }

    for (size_t i = 1; i <= data_size; ++i) {
        dlamda[i] = (real)(1.0 + sin(i));
        w[i] = (real)(cos(i) * cos(i));
        indx[i] = rand() % data_size + 1;
    }
}