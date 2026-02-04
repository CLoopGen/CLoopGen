#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *n;
doublecomplex *b;
doublereal *rwork;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer j;
integer jcol;
integer jrow;

void init_vars() {
    const integer data_size = 8000;
    
    n = (integer*)malloc(sizeof(integer));
    *n = data_size;
    
    b_dim1 = data_size;
    i__1 = data_size;
    
    size_t b_elements = (data_size + 1) * (data_size + 1);
    b = (doublecomplex*)calloc(b_elements, sizeof(doublecomplex));
    
    size_t rwork_size = data_size * data_size + 10;
    rwork = (doublereal*)calloc(rwork_size, sizeof(doublereal));
    
    j = 0;
    jcol = 0;
    jrow = 0;
    i__2 = 0;
    i__3 = 0;
}