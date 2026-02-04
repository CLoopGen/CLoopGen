#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *n;
doublereal *c__;
doublereal *s;
doublereal *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
doublereal temp;
doublereal ctemp;
doublereal stemp;

static doublereal a_data[256 * 1024 * 1024 / sizeof(doublereal)]; // ~256 MB for 'a'
static doublereal c_data[65536];
static doublereal s_data[65536];

void init_vars() {
    // Allocate and initialize n
    n = (integer*)malloc(sizeof(integer));
    *n = 4096;  // Size of matrix columns

    // Set dimensions
    a_dim1 = *n;  // Leading dimension of matrix 'a'

    // Set loop bounds
    i__1 = 1024;  // j from 2 to i__1 (must be <= allocated size for c__ and s)

    // Initialize c__ and s arrays with meaningful values
    c__ = c_data;
    s = s_data;

    for (int idx = 0; idx < 65536; ++idx) {
        c__[idx] = (idx < (i__1)) ? (idx % 2 == 0 ? 1.0 : 0.8) : 0.0;
        s[idx] = (idx < (i__1)) ? (idx % 2 == 0 ? 0.0 : 0.6) : 0.0;
    }

    // Initialize matrix 'a' as a large column-major array: a[*n][*n]
    a = a_data;

    for (int col = 0; col < *n; ++col) {
        for (int row = 0; row < *n; ++row) {
            a[row + col * a_dim1] = (doublereal)(row + col + 1);
        }
    }

    // Ensure no out-of-bounds access in loop
    if (i__1 > 65536) i__1 = 65536;
    if (i__1 > *n) i__1 = *n;

    // Initialize scalars used in loop
    i__ = 0;
    j = 0;
    temp = 0.0;
    ctemp = 0.0;
    stemp = 0.0;
}