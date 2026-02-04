#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
doublereal safmx2;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of doublecomplex data (~131k elements)
    
    doublecomplex *data = (doublecomplex*)calloc(data_size, sizeof(doublecomplex));
    if (!data) exit(1);

    for (size_t i = 0; i < data_size; ++i) {
        data[i].r = (doublereal)(i % 100) / 10.0;
        data[i].i = (doublereal)((i + 10) % 100) / 15.0;
    }

    r__ = data;
    i__1 = (integer)data_size - 1;
    safmx2 = 2.0;
    i__ = 0;
    z__1.r = 0.0;
    z__1.i = 0.0;
}