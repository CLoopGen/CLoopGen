#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int integer;
typedef float real;

integer *nl;
real *d__;
real *z__;
real *vf;
real *vl;
real *alpha;
integer *idxq;
integer i__;

static size_t data_size = 0;

void init_vars() {
    data_size = (1 << 20); // Approximately 1M elements for ~0.01 sec runtime

    nl = (integer*)malloc(sizeof(integer));
    *nl = (integer)(data_size - 1);

    d__ = (real*)malloc((data_size + 1) * sizeof(real));
    z__ = (real*)malloc((data_size + 1) * sizeof(real));
    vf = (real*)malloc((data_size + 1) * sizeof(real));
    vl = (real*)malloc((data_size + 1) * sizeof(real));
    idxq = (integer*)malloc((data_size + 1) * sizeof(integer));
    alpha = (real*)malloc(sizeof(real));

    *alpha = 1.5f;

    for (size_t i = 0; i <= data_size; ++i) {
        d__[i] = (real)(i);
        z__[i] = 0.0f;
        vf[i] = (real)(i % 100);
        vl[i] = (real)(i % 50);
        idxq[i] = (integer)(i);
    }

    i__ = 0;
}