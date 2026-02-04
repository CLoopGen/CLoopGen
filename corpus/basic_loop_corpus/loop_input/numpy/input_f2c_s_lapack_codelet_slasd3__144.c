#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *vt2;
integer vt2_dim1;
integer i__1;
integer i__;
integer nlp2;
integer ktemp;

void init_vars() {
    // Set problem size to achieve ~0.01 sec runtime
    // Use a 2D array layout: vt2 is accessed as [ktemp + i__ * vt2_dim1] and [i__ * vt2_dim1 + 1]
    // To avoid out-of-bounds, we need sufficient row and column sizes

    vt2_dim1 = 2048;                    // leading dimension (columns)
    nlp2 = 1;                           // loop start index
    i__1 = 1024;                        // loop end index (less than vt2_dim1 to be safe)
    ktemp = 1024;                       // offset applied to destination index

    // Maximum source index: i__1 * vt2_dim1 + 1 = 1024 * 2048 + 1 = ~2.1M
    // Maximum dest index: ktemp + i__1 * vt2_dim1 = 1024 + 1024*2048 = ~2.1M
    // So we need at least ~2.1M elements, allocate slightly more for safety
    size_t vt2_size = (ktemp + i__1 * vt2_dim1 + 1) + 1024;
    vt2 = (real*)calloc(vt2_size, sizeof(real));
    if (!vt2) {
        exit(1);
    }

    // Initialize source region to non-zero to ensure meaningful data movement
    for (integer i = nlp2; i <= i__1; ++i) {
        vt2[i * vt2_dim1 + 1] = (real)(i & 0xFF);
    }
}