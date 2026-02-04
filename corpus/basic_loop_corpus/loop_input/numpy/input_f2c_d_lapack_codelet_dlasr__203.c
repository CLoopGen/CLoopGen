#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer *m;
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

static doublereal a_data[200000];
static doublereal c_data[1000];
static doublereal s_data[1000];

void init_vars() {
    const integer data_size = 1000;
    const integer matrix_rows = 200;
    
    m = (integer*)malloc(sizeof(integer));
    *m = matrix_rows;
    
    a_dim1 = matrix_rows;
    
    i__1 = data_size - 1;
    if (i__1 >= 1000) i__1 = 999;
    
    c__ = c_data;
    s = s_data;
    a = a_data;
    
    for (integer idx = 0; idx < data_size; ++idx) {
        c__[idx] = cos(idx * 0.1);
        s[idx] = sin(idx * 0.1);
    }
    
    for (integer j = 0; j < data_size; ++j) {
        for (integer i = 0; i < matrix_rows; ++i) {
            a[i + j * a_dim1] = (doublereal)(i * j + 1);
        }
    }
    
    i__ = 0;
    j = 0;
    temp = 0.0;
    ctemp = 0.0;
    stemp = 0.0;
}