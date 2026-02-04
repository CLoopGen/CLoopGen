#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *m;
doublereal *alpha;
doublereal *x;
integer *incx;
doublereal *y;
integer *incy;
doublereal *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer ix;
integer jy;
integer kx;
doublereal temp;

#define M_SIZE 2048
#define N_SIZE 128

void init_vars() {
    m = (integer*)malloc(sizeof(integer));
    alpha = (doublereal*)malloc(sizeof(doublereal));
    incx = (integer*)malloc(sizeof(integer));
    incy = (integer*)malloc(sizeof(integer));
    
    *m = M_SIZE;
    *alpha = 1.5;
    *incx = 1;
    *incy = 1;
    
    x = (doublereal*)calloc(M_SIZE, sizeof(doublereal));
    y = (doublereal*)calloc(N_SIZE, sizeof(doublereal));
    a = (doublereal*)calloc(M_SIZE * N_SIZE, sizeof(doublereal));
    
    a_dim1 = M_SIZE;
    i__1 = N_SIZE;
    i__2 = M_SIZE;
    
    i__ = 0;
    j = 0;
    ix = 0;
    jy = 0;
    kx = 0;
    temp = 0.0;
    
    for (integer i = 0; i < M_SIZE; ++i) {
        x[i] = (doublereal)(i % 100) / 10.0;
    }
    
    for (integer j = 0; j < N_SIZE; ++j) {
        y[j] = (j % 3) ? (doublereal)(j % 50) / 25.0 : 0.0;
    }
    
    for (integer i = 0; i < M_SIZE; ++i) {
        for (integer j = 0; j < N_SIZE; ++j) {
            a[i + j * a_dim1] = (doublereal)((i + j) % 100) / 50.0;
        }
    }
    
    kx = 1;
    jy = 1;
}