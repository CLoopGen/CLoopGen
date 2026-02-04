#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

typedef double doublereal;
typedef int integer;

doublereal *alpha;
doublereal *a;
doublereal *x;
doublereal *y;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
doublereal temp1;
doublereal temp2;

void init_vars() {
    const int n = 2048;  // Adjust size to get ~0.01 sec runtime on modern CPU
    
    a_dim1 = n;
    i__1 = n;

    alpha = (doublereal*)malloc(sizeof(doublereal));
    x = (doublereal*)malloc(n * sizeof(doublereal));
    y = (doublereal*)malloc(n * sizeof(doublereal));
    a = (doublereal*)malloc(n * n * sizeof(doublereal));

    *alpha = 1.5;
    for (int idx = 0; idx < n; ++idx) {
        x[idx] = 1.0 + idx * 0.001;
        y[idx] = 2.0 - idx * 0.0005;
    }
    for (int idx = 0; idx < n * n; ++idx) {
        a[idx] = (idx % 7) * 0.1;
    }

    temp1 = 0.0;
    temp2 = 0.0;
    i__ = 0;
    j = 0;
    i__2 = 0;
}