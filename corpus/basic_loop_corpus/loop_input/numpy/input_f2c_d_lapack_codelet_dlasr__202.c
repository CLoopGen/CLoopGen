#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *m;
integer *n;
doublereal *c__;
doublereal *s;
doublereal *a;
integer a_dim1;
integer i__1;
integer i__;
integer j;
doublereal temp;
doublereal ctemp;
doublereal stemp;

static doublereal* m_storage;
static doublereal* n_storage;
static doublereal* c_storage;
static doublereal* s_storage;
static doublereal* a_storage;

void init_vars() {
    // Allocate scalars via storage to allow taking addresses
    m_storage = (doublereal*)aligned_alloc(32, sizeof(integer));
    n_storage = (doublereal*)aligned_alloc(32, sizeof(integer));
    m = (integer*)m_storage;
    n = (integer*)n_storage;

    // Set problem size to achieve ~0.01s runtime
    // Based on typical performance: aim for several million operations
    *m = 2000;  // rows of matrix a
    *n = 1000;  // columns of matrix a

    a_dim1 = *m;  // leading dimension

    // c__ and s are arrays of length *n, indexed from 1 to *n-1 in loop
    size_t c_size = (*n) * sizeof(doublereal);
    c_storage = (doublereal*)aligned_alloc(32, c_size);
    s_storage = (doublereal*)aligned_alloc(32, c_size);
    c__ = c_storage;
    s = s_storage;

    // a is a matrix of size m x n, column-major
    size_t a_size = (*m) * (*n) * sizeof(doublereal);
    a_storage = (doublereal*)aligned_alloc(32, a_size);

    a = a_storage;

    // Initialize c__ and s arrays
    for (int j = 0; j < *n; ++j) {
        c__[j] = j % 2 ? 1.0 : 0.8;
        s[j] = j % 2 ? 0.0 : 0.6;
    }

    // Initialize matrix a with non-zero values
    for (int i = 0; i < *m; ++i) {
        for (int j = 0; j < *n; ++j) {
            a[i + j * a_dim1] = (doublereal)(i + j);
        }
    }

    // Initialize loop indices and temporaries
    i__ = 0;
    j = 0;
    temp = 0.0;
    ctemp = 0.0;
    stemp = 0.0;
}