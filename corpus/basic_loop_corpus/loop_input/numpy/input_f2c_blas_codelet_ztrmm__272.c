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

typedef int logical;

integer *m;
integer *n;
doublecomplex *alpha;
doublecomplex *a;
doublecomplex *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
doublecomplex z__1;
doublecomplex z__2;
integer i__;
integer j;
integer k;
doublecomplex temp;
logical nounit;

static integer s_m;
static integer s_n;
static doublecomplex s_alpha;
static doublecomplex *s_a;
static doublecomplex *s_b;

void init_vars() {
    s_m = 512;
    s_n = 512;
    m = &s_m;
    n = &s_n;
    alpha = &s_alpha;
    alpha->r = 1.0;
    alpha->i = 0.0;
    a_dim1 = s_n;
    b_dim1 = s_m;

    nounit = 1;

    s_a = (doublecomplex*)calloc((size_t)(a_dim1 * s_n), sizeof(doublecomplex));
    s_b = (doublecomplex*)calloc((size_t)(b_dim1 * s_n), sizeof(doublecomplex));

    if (!s_a || !s_b) {
        exit(1);
    }

    a = s_a;
    b = s_b;

    for (integer idx = 0; idx < s_n; ++idx) {
        a[idx + idx * a_dim1].r = 1.0;
        a[idx + idx * a_dim1].i = 0.0;
    }

    for (integer i = 1; i <= s_m; ++i) {
        for (integer j = 1; j <= s_n; ++j) {
            integer idx = (i - 1) + (j - 1) * b_dim1;
            b[idx].r = (doublereal)(i % 17 + j % 19);
            b[idx].i = (doublereal)(i % 13 - j % 11);
        }
    }

    for (integer k = 1; k <= s_n; ++k) {
        for (integer j = k + 1; j <= s_n; ++j) {
            integer idx = (k - 1) + (j - 1) * a_dim1;
            a[idx].r = (doublereal)(k % 5);
            a[idx].i = (doublereal)(j % 7);
        }
    }
}