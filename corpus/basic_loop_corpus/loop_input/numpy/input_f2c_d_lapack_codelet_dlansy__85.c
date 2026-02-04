#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer *n;
doublereal *a;
doublereal *work;
integer a_dim1;
integer i__1;
integer i__2;
doublereal d__1;
integer i__;
integer j;
doublereal sum;
doublereal absa;
doublereal value;

static integer n_storage;
static doublereal *a_storage;
static doublereal *work_storage;

void init_vars() {
    n_storage = 2048;  // ~16MB for 'a' matrix: 2048*2048*sizeof(double) ≈ 32MB, plus work array
    a_dim1 = n_storage;
    i__1 = n_storage;
    n = &n_storage;

    // Allocate and initialize a: row-major access assumed via [i__ + j * a_dim1]
    a_storage = (doublereal *)calloc(n_storage * n_storage, sizeof(doublereal));
    if (!a_storage) exit(1);
    for (int idx = 0; idx < n_storage * n_storage; ++idx) {
        a_storage[idx] = (doublereal)(rand() % 100) / 100.0;
    }
    a = a_storage;

    // Allocate and initialize work array of size n_storage
    work_storage = (doublereal *)calloc(n_storage, sizeof(doublereal));
    if (!work_storage) exit(1);
    for (int i = 0; i < n_storage; ++i) {
        work_storage[i] = (doublereal)(rand() % 50);
    }
    work = work_storage;

    // Initialize scalars used in computation
    sum = 0.0;
    absa = 0.0;
    value = 0.0;
    i__ = 1;
    j = 1;
    d__1 = 0.0;
}