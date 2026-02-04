#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *r__ = NULL;
integer i__1;
singlecomplex q__1;
integer i__;
real safmn2;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of complex numbers: 2^20 elements

    singlecomplex *data = (singlecomplex*)calloc(data_size, sizeof(singlecomplex));
    if (!data) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        data[idx].r = (real)(idx % 100) / 10.0f;
        data[idx].i = (real)((idx + 10) % 100) / 15.0f;
    }

    r__ = data;
    i__1 = (integer)(data_size - 1); 
    i__ = 0;
    safmn2 = 0.5f;
}