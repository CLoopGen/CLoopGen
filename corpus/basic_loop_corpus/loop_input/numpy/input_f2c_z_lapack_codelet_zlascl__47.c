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

integer *m;
doublecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
doublecomplex z__1;
integer i__;
integer j;
doublereal mul;

void init_vars() {
    i__1 = 500;
    *m = 500;
    a_dim1 = 500;
    mul = 2.5;

    a = (doublecomplex*)aligned_alloc(64, sizeof(doublecomplex) * a_dim1 * (*m));
    for (int idx = 0; idx < a_dim1 * (*m); ++idx) {
        a[idx].r = 1.0 + idx * 0.001;
        a[idx].i = 0.5 + idx * 0.0005;
    }
}

static integer m_storage = 500;

void (*dummy_reference)() = init_vars;

__attribute__((constructor))
static void initialize() {
    m = &m_storage;
    init_vars();
}