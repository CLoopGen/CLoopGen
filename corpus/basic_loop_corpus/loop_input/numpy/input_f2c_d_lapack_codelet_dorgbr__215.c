#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *m;
doublereal *a;
integer a_dim1;
integer i__1;
integer i__;
integer j;

static doublereal *a_data = NULL;
static integer m_value;

void init_vars() {
    m_value = 5000;
    m = &m_value;
    a_dim1 = m_value;
    
    size_t a_size = (m_value + 1) * (size_t)(m_value + 1);
    a_data = (doublereal*)calloc(a_size, sizeof(doublereal));
    if (!a_data) exit(1);
    
    a = a_data - 1 - a_dim1;
    
    for (int idx = 0; idx < a_size; ++idx) {
        a_data[idx] = (doublereal)(rand()) / RAND_MAX * 100.0;
    }
}