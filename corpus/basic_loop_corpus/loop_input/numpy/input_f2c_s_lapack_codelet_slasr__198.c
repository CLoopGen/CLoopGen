#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *m;
integer *n;
real *c__;
real *s;
real *a;
integer a_dim1;
integer i__1;
integer i__;
integer j;
real temp;
real ctemp;
real stemp;

void init_vars() {
    // Allocate and initialize scalar pointers
    m = (integer*)malloc(sizeof(integer));
    n = (integer*)malloc(sizeof(integer));
    c__ = (real*)malloc(256 * sizeof(real));
    s = (real*)malloc(256 * sizeof(real));
    
    // Set matrix dimensions: aim for ~64MB of data to ensure ~0.01s runtime
    *m = 256;        // rows
    *n = 1024;       // columns
    a_dim1 = *m;     // leading dimension
    
    // Total size: a is m x n -> 256 * 1024 * sizeof(float) = 1,048,576 bytes (~1MB)
    // This ensures reasonable runtime without being too large
    a = (real*)calloc(*m * (*n), sizeof(real));
    
    // Initialize c__ and s arrays with meaningful values
    for (int idx = 0; idx < 255; ++idx) {
        c__[idx] = cosf(0.1f * idx);
        s[idx] = sinf(0.1f * idx);
    }
    // Ensure at least one iteration enters the conditional
    c__[255] = 0.5f;
    s[255] = 0.866f;
    
    // Initialize a with non-zero values to allow computation effects
    for (int i = 1; i <= *m; ++i) {
        for (int j = 1; j <= *n; ++j) {
            a[i + j * a_dim1] = (real)(i % 100) + (j % 50) * 0.1f;
        }
    }
    
    // Initialize loop temporaries
    temp = 0.0f;
    ctemp = 0.0f;
    stemp = 0.0f;
    i__ = 0;
    i__1 = 0;
}