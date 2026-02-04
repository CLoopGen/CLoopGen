#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;

real *sa;
real *sx;
integer i__2;
integer i__;
integer mp1;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB of data for sx
    sx = (real*)aligned_alloc(32, data_size);
    
    if (!sx) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size / sizeof(real); ++idx) {
        sx[idx] = (real)(idx % 1000) + 1.0f;
    }

    sa = (real*)aligned_alloc(32, sizeof(real));
    if (!sa) {
        exit(1);
    }
    *sa = 1.5f;

    mp1 = 0;
    i__2 = (data_size / sizeof(real)) - 5;

    i__ = 0;
}