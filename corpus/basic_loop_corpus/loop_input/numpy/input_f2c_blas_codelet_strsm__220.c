#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *m;
real *b;
integer b_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

static real *b_data = NULL;
static integer m_value;

void init_vars() {
    i__1 = 500;        
    m_value = 500;     
    m = &m_value;       

    b_dim1 = m_value;   
    size_t b_size = (size_t)(m_value + 1) * (size_t)(i__1 + 1);
    b_data = (real*)calloc(b_size, sizeof(real));
    if (!b_data) {
        exit(1);
    }
    b = b_data;
}