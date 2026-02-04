#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *m;
singlecomplex *c__;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    const int M_SIZE = 8000;
    const int N_SIZE = 8000;

    i__1 = N_SIZE;
    c_dim1 = M_SIZE + 1;
    
    m = (integer*)malloc(sizeof(integer));
    if (!m) exit(1);
    *m = M_SIZE;

    size_t total_size = (M_SIZE + 1) * (N_SIZE + 1);
    c__ = (singlecomplex*)calloc(total_size, sizeof(singlecomplex));
    if (!c__) exit(1);
}