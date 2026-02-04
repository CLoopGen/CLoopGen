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

integer m_storage;
integer *m = &m_storage;

singlecomplex *a;
integer a_dim1;

integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    a_dim1 = 1024;
    m_storage = 1024;
    
    size_t total_size = (size_t)(m_storage + 1) * (a_dim1 + 1);
    a = (singlecomplex*)calloc(total_size, sizeof(singlecomplex));
    
    if (!a) {
        exit(1);
    }
}