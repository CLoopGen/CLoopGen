#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *n;
doublecomplex *b;
doublereal *rwork;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
doublecomplex z__1;
integer jcol;
integer jrow;
integer jimag;
integer jreal;

static integer n_val;
static integer b_size;
static size_t rwork_size;

void init_vars() {
    n_val = 1000;
    n = &n_val;

    b_dim1 = n_val;
    i__1 = 500;  

    b_size = (n_val + 1) * (i__1 + 1);
    b = (doublecomplex*)calloc(b_size, sizeof(doublecomplex));
    if (!b) exit(1);

    rwork_size = (i__1 * n_val * 2) + 100;
    rwork = (doublereal*)malloc(rwork_size * sizeof(doublereal));
    if (!rwork) exit(1);

    for (size_t i = 0; i < rwork_size; ++i) {
        rwork[i] = (doublereal)(i % 100) / 3.0;
    }

    jreal = 0;
    jimag = (i__1 * n_val); 

    i__2 = *n;
}