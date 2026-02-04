#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer *m;
doublereal *alpha;
doublereal *x;
doublereal *y;
integer *incy;
doublereal *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer jy;
doublereal temp;

#define M_SIZE 2048
#define N_SIZE 128

void init_vars() {
    m = (integer*)malloc(sizeof(integer));
    alpha = (doublereal*)malloc(sizeof(doublereal));
    incy = (integer*)malloc(sizeof(integer));
    
    *m = M_SIZE;
    *alpha = 1.5;
    *incy = 1;
    
    i__1 = N_SIZE;
    
    x = (doublereal*)calloc(M_SIZE + 1, sizeof(doublereal));
    y = (doublereal*)calloc(N_SIZE * abs(*incy) + 1, sizeof(doublereal));
    a_dim1 = M_SIZE;
    a = (doublereal*)calloc((M_SIZE + 1) * (N_SIZE + 1), sizeof(doublereal));
    
    for (i__ = 1; i__ <= M_SIZE; ++i__) {
        x[i__] = sin(i__) * 0.1;
    }
    
    for (j = 1; j <= N_SIZE; ++j) {
        y[j * abs(*incy)] = (j % 3 == 0) ? 0.0 : (cos(j) * 0.2);
    }
    
    jy = 1;
}