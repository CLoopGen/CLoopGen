#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *vt;
doublereal *vt2;
integer vt_dim1;
integer vt2_dim1;
integer i__1;
doublereal c__;
integer i__;
integer m;
doublereal s;
integer nlp1;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data for sufficient runtime (~0.01 sec on modern CPU)
    const size_t num_elements = data_size / sizeof(doublereal);

    // Allocate vt and vt2 as 2D-like arrays stored in row-major order
    vt = (doublereal*)aligned_alloc(32, data_size);
    vt2 = (doublereal*)aligned_alloc(32, data_size);

    if (!vt || !vt2) {
        exit(1);
    }

    // Set dimensions to interpret arrays as 2D: assume square-ish layout
    vt_dim1 = (integer)num_elements / 1024;
    vt2_dim1 = (integer)num_elements / 1024;

    // Ensure valid access within the loop: set loop bound so that all accesses are in range
    i__1 = 1024; // number of iterations

    // Choose m and nlp1 such that m + i__*vt_dim1 and nlp1 + i__*vt_dim1 stay within [0, num_elements)
    m = 0;
    nlp1 = 512;

    // Adjust i__1 to prevent out-of-bounds access
    while (m + i__1 * vt_dim1 >= num_elements || nlp1 + i__1 * vt_dim1 >= num_elements) {
        --i__1;
    }

    // Initialize scalar values
    c__ = 0.75;
    s = 0.25;

    // Initialize array elements to avoid undefined behavior
    for (size_t i = 0; i < num_elements; ++i) {
        vt[i] = (doublereal)(i % 100) * 0.1;
        vt2[i] = (doublereal)((i + 10) % 100) * 0.1;
    }
}