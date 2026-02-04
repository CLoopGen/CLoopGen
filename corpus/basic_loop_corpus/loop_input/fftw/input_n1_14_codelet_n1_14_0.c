#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *ri;
R *ii;
R *ro;
R *io;
stride is;
stride os;
INT v;
INT ivs;
INT ovs;
E KP222520933 = 0.222520933;
E KP900968867 = 0.900968867;
E KP623489801 = 0.623489801;
E KP433883739 = 0.433883739;
E KP781831482 = 0.781831482;
E KP974927912 = 0.974927912;
INT i;

#define DATA_SIZE (1 << 20)  // ~16MB total data, adjust as needed for ~0.01s runtime

void init_vars() {
    // Allocate arrays with sufficient size to prevent out-of-bounds access
    ri = (R*)aligned_alloc(sizeof(R), DATA_SIZE * sizeof(R));
    ii = (R*)aligned_alloc(sizeof(R), DATA_SIZE * sizeof(R));
    ro = (R*)aligned_alloc(sizeof(R), DATA_SIZE * sizeof(R));
    io = (R*)aligned_alloc(sizeof(R), DATA_SIZE * sizeof(R));
    is = (INT*)aligned_alloc(sizeof(INT), 14 * sizeof(INT));
    os = (INT*)aligned_alloc(sizeof(INT), 14 * sizeof(INT));

    // Initialize strides: assume unit stride for input/output spacing
    for (int idx = 0; idx < 14; ++idx) {
        is[idx] = idx;
        os[idx] = idx;
    }

    // Set vectorization and stride parameters
    ivs = 1;
    ovs = 1;

    // Set loop count v to a reasonable value that uses allocated data safely
    v = DATA_SIZE / 14;  // Ensure we don't exceed array bounds during loop accesses

    // Initialize input data to avoid NaN/undefined behavior
    for (size_t j = 0; j < DATA_SIZE; ++j) {
        ri[j] = sin(j * 0.01);
        ii[j] = cos(j * 0.01);
        ro[j] = 0.0;
        io[j] = 0.0;
    }
}