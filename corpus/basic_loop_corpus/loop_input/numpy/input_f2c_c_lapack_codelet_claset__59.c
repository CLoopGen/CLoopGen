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

singlecomplex *beta;
singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;

void init_vars() {
    const size_t data_size = 1 << 20; // 1M complex numbers ~ 8MB total for 'a'
    a_dim1 = (integer)32768; // Ensure stride fits in memory
    i__1 = (integer)32768;

    // Allocate beta as a single complex value
    beta = (singlecomplex*)calloc(1, sizeof(singlecomplex));
    beta->r = 1.0f;
    beta->i = 0.5f;

    // Allocate array 'a' with sufficient size to cover index: i__ + i__ * a_dim1 where i__ <= i__1
    // Maximum index: i__1 + i__1 * a_dim1 = i__1 * (a_dim1 + 1)
    ptrdiff_t max_index = (ptrdiff_t)i__1 * (a_dim1 + 1);
    if (max_index >= (ptrdiff_t)data_size) {
        max_index = (ptrdiff_t)data_size - 1;
        i__1 = max_index / (a_dim1 + 1);
    }

    a = (singlecomplex*)calloc(data_size, sizeof(singlecomplex));
}