#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

doublecomplex *r__ = NULL;
integer i__1;
doublecomplex z__1;
integer i__;
doublereal safmn2;

void init_vars() {
    const size_t data_size = 1 << 20; // ~16MB of complex data (2^20 elements)
    
    doublecomplex *data = (doublecomplex*)calloc(data_size, sizeof(doublecomplex));
    if (!data) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        data[idx].r = (doublereal)(idx % 1000) / 100.0;
        data[idx].i = (doublereal)((idx + 5) % 1000) / 100.0;
    }

    r__ = data;
    i__1 = (integer)data_size;
    i__ = 0;
    safmn2 = 0.5;
    z__1.r = 0.0;
    z__1.i = 0.0;
}