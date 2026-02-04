#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int integer;
typedef double doublereal;

integer *n;
doublereal *a;
integer *ipiv;
integer *incx;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer k;
integer i1;
integer n32;
integer ip;
integer ix;
doublereal temp;

static doublereal *a_data = NULL;
static integer *ipiv_data = NULL;

void init_vars() {
    const int N_VAL = 1024;  // Matrix size ~8MB for a (double precision)
    
    // Allocate and initialize n
    n = (integer*)malloc(sizeof(integer));
    *n = N_VAL;

    // Allocate matrix a with dimensions [N_VAL+1][N_VAL+1] (1-indexed assumed)
    a_dim1 = N_VAL + 1;
    size_t a_size = (size_t)(a_dim1) * (N_VAL + 1);
    a_data = (doublereal*)calloc(a_size, sizeof(doublereal));
    a = a_data;

    // Initialize a with non-zero values to simulate real data
    for (int i = 1; i <= N_VAL; ++i) {
        for (int j = 1; j <= N_VAL; ++j) {
            a[i + j * a_dim1] = (doublereal)(i * N_VAL + j + 1);
        }
    }

    // Allocate and initialize ipiv
    ipiv_data = (integer*)malloc((N_VAL + 1) * sizeof(integer));
    ipiv = ipiv_data;
    for (int i = 1; i <= N_VAL; ++i) {
        ipiv[i] = (rand() % N_VAL) + 1;  // Random pivot indices
    }

    // Set incx
    incx = (integer*)malloc(sizeof(integer));
    *incx = 1;

    // Set loop bounds to ensure valid access
    i1 = 1;
    n32 = 1;
    i__3 = -1;  // reverse iteration
    i__1 = N_VAL;  // upper bound
    i__ = i1;
    ix = 1;

    // Ensure that initial values of i__, i__1, i__3 make loop condition valid
    if (i__3 < 0) {
        // Counting down: must start >= i__1
        i__ = i__1;
    } else {
        i__ = i1;
    }
}