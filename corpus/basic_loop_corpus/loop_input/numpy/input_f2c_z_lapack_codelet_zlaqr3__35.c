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

doublecomplex *sh;
doublecomplex *t;
integer t_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer infqr;
integer kwtop;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~100MB of doublecomplex data
    const size_t num_elements = data_size / sizeof(doublecomplex);

    sh = (doublecomplex*)aligned_alloc(32, data_size);
    t = (doublecomplex*)aligned_alloc(32, data_size);

    for (size_t idx = 0; idx < num_elements; ++idx) {
        t[idx].r = (doublereal)(idx * 1.5);
        t[idx].i = (doublereal)(idx * 2.7);
    }

    t_dim1 = num_elements > 10000 ? 10000 : num_elements;
    infqr = 1;
    kwtop = 1;
    i__1 = (num_elements < 10000) ? num_elements - kwtop : 9998;

    if (i__1 <= infqr) {
        i__1 = infqr + 1;
    }

    for (i__ = infqr + 1; i__ <= i__1; ++i__) {
        i__2 = kwtop + i__ - 1;
        i__3 = i__ + i__ * t_dim1;
        if ((size_t)i__2 >= num_elements) {
            i__1 = i__ - 1;
            break;
        }
        if ((size_t)i__3 >= num_elements) {
            i__1 = i__ - 1;
            break;
        }
    }
}