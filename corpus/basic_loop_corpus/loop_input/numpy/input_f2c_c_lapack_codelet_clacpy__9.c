#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *m;
singlecomplex *a;
singlecomplex *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__;
integer j;

static singlecomplex *a_data;
static singlecomplex *b_data;
static integer m_val;
static integer matrix_size;

void init_vars() {
    matrix_size = 8000;
    m_val = matrix_size;
    i__1 = matrix_size;
    a_dim1 = matrix_size;
    b_dim1 = matrix_size;

    m = &m_val;

    a_data = (singlecomplex*)calloc(matrix_size * matrix_size, sizeof(singlecomplex));
    b_data = (singlecomplex*)calloc(matrix_size * matrix_size, sizeof(singlecomplex));

    if (!a_data || !b_data) {
        exit(1);
    }

    a = a_data;
    b = b_data;

    for (int idx = 0; idx < matrix_size * matrix_size; ++idx) {
        a_data[idx].r = (real)(idx % 100) + 0.5f;
        a_data[idx].i = (real)(idx % 50) + 0.25f;
    }
}