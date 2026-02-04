#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef float real;
typedef int integer;

real *vt;
real *vt2;
integer vt_dim1;
integer vt2_dim1;
integer i__1;
real c__;
integer i__;
integer m;
real s;
integer nlp2;

static real *vt_data;
static real *vt2_data;

void init_vars() {
    const size_t target_bytes = 64 * 1024 * 1024; // ~64 MB for balanced workload
    const size_t total_elements = target_bytes / (sizeof(real) * 2); // Two arrays
    const size_t sqrt_elements = (size_t)sqrt((double)total_elements);
    
    vt_dim1 = (integer)sqrt_elements + 1;
    vt2_dim1 = (integer)sqrt_elements + 1;
    
    size_t vt_size = (sqrt_elements + 10) * vt_dim1; // Add padding
    size_t vt2_size = (sqrt_elements + 10) * vt2_dim1;
    
    vt_data = (real*)aligned_alloc(32, vt_size * sizeof(real));
    vt2_data = (real*)aligned_alloc(32, vt2_size * sizeof(real));
    
    if (!vt_data || !vt2_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    memset(vt_data, 0, vt_size * sizeof(real));
    memset(vt2_data, 0, vt2_size * sizeof(real));
    
    vt = vt_data;
    vt2 = vt2_data;
    
    c__ = 0.98f;
    s = 0.15f;
    m = 1;
    nlp2 = 2;
    i__1 = (integer)(sqrt_elements - 1);
    
    if (nlp2 > i__1) {
        nlp2 = i__1;
    }
}