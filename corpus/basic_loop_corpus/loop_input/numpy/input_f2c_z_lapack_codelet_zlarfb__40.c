#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

doublecomplex *c__ = NULL;
doublecomplex *work = NULL;
integer c_dim1 = 0;
integer work_dim1 = 0;
integer i__1 = 0;
integer i__2 = 0;
integer i__3 = 0;
integer i__4 = 0;
integer i__5 = 0;
doublecomplex z__1;
integer i__ = 0;
integer j = 0;
integer lastc = 0;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64 MB of data for c__ and work
    const size_t element_size = sizeof(doublecomplex);

    i__1 = 1000;
    lastc = (total_data_size / (i__1 * element_size)) + 1;
    if (lastc < 1) lastc = 1;

    c_dim1 = lastc;
    work_dim1 = lastc;

    size_t c_size = (lastc + 1) * (i__1 + 1);
    size_t work_size = (lastc + 1) * (i__1 + 1);

    c__ = (doublecomplex*)calloc(c_size, element_size);
    work = (doublecomplex*)calloc(work_size, element_size);

    if (!c__ || !work) {
        fprintf(stderr, "init_vars: allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < c_size; ++idx) {
        c__[idx].r = (doublereal)(idx % 100) / 10.0;
        c__[idx].i = (doublereal)(idx % 73) / 10.0;
    }

    for (size_t idx = 0; idx < work_size; ++idx) {
        work[idx].r = (doublereal)((idx + 10) % 97) / 13.0;
        work[idx].i = (doublereal)((idx + 15) % 89) / 17.0;
    }
}