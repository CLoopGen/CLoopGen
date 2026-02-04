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
    // Set scalar values
    i__1 = 500;
    a_dim1 = 1000;
    *m = 1000;
    mul = 2.5;

    // Allocate arrays
    a = (doublecomplex*)calloc(a_dim1 * (*m) + 1, sizeof(doublecomplex));
    if (!a) {
        exit(1);
    }
}

// Define m after allocation so we can initialize it dynamically
static integer m_storage = 1000;
integer *m = &m_storage;