#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;
typedef int logical;

integer *m;
doublereal *alpha;
doublereal *a;
doublereal *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer k;
doublereal temp;
logical nounit;

static integer m_value;
static doublereal alpha_value;
static doublereal *a_data;
static doublereal *b_data;

void init_vars() {
    // Set matrix dimensions: aim for ~64MB of data to ensure ~0.01s runtime
    m_value = 2048;
    i__1 = 2048;  // j loop bound
    a_dim1 = m_value;
    b_dim1 = m_value;
    
    // Allocate matrices A (m x m) and B (m x i__1)
    size_t a_size = (size_t)m_value * m_value;
    size_t b_size = (size_t)m_value * i__1;
    
    a_data = (doublereal*)calloc(a_size, sizeof(doublereal));
    b_data = (doublereal*)calloc(b_size, sizeof(doublereal));
    
    if (!a_data || !b_data) {
        exit(1);
    }
    
    // Initialize diagonal of A to non-unit values
    for (integer idx = 0; idx < m_value; ++idx) {
        a_data[idx + idx * m_value] = 1.5;
    }
    
    // Fill lower triangle of A
    for (integer i = 0; i < m_value; ++i) {
        for (integer k = i + 1; k < m_value; ++k) {
            a_data[k + i * m_value] = (doublereal)(i + k) / m_value;
        }
    }
    
    // Initialize B with random-like values
    for (integer i = 0; i < m_value; ++i) {
        for (integer j = 0; j < i__1; ++j) {
            b_data[i + j * m_value] = (doublereal)(i + 1) * (j + 1) / (m_value * m_value);
        }
    }
    
    // Assign external pointers
    m = &m_value;
    alpha = &alpha_value;
    a = a_data;
    b = b_data;
    *alpha = 0.8;
    nounit = 1;
    
    // Ensure loop bounds are safe
    i__2 = *m;
    i__3 = *m;
}