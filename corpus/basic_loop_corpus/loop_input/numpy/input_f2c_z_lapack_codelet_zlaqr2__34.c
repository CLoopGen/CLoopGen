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
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of complex data
    const size_t num_elements = data_size / sizeof(doublecomplex);

    // Allocate sh and t arrays
    sh = (doublecomplex*)aligned_alloc(32, data_size);
    t = (doublecomplex*)aligned_alloc(32, data_size);

    // Initialize all array elements to prevent undefined behavior
    for (size_t idx = 0; idx < num_elements; ++idx) {
        sh[idx].r = (doublereal)(idx % 100) + 0.1;
        sh[idx].i = (doublereal)(idx % 100) - 0.1;
        t[idx].r = (doublereal)((idx + 10) % 100) + 0.2;
        t[idx].i = (doublereal)((idx + 10) % 100) - 0.2;
    }

    // Set matrix dimension stride
    t_dim1 = num_elements > 10000 ? 10000 : (num_elements > 1 ? (int)num_elements : 1);

    // Set loop bounds to ensure safe access within allocated memory
    infqr = 100;
    i__1 = 5000;  // ensures i__ runs from infqr+1 to i__1

    // Ensure kwtop + i__ - 1 stays in bounds for sh
    kwtop = 1000;

    // Validate that the maximum index into sh is within bounds
    if (kwtop + i__1 - 1 >= num_elements) {
        i__1 = num_elements - kwtop;  // clamp i__1 to prevent overflow
    }

    // Validate that i__ + i__*t_dim1 stays in bounds for t
    while (i__1 + i__1 * t_dim1 >= num_elements) {
        --i__1;
    }

    // Initialize scratch variables to zero (they are modified in loop)
    i__2 = 0;
    i__3 = 0;
    i__ = 0;
}