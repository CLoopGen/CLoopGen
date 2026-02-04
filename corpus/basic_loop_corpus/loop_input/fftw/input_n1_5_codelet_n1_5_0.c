#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
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
E KP250000000;
E KP587785252;
E KP951056516;
E KP559016994;
INT i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~16MB of complex data (each array is 8MB)
    const INT vector_length = 5;
    
    ri = (R*)aligned_alloc(32, data_size * sizeof(R));
    ii = (R*)aligned_alloc(32, data_size * sizeof(R));
    ro = (R*)aligned_alloc(32, data_size * sizeof(R));
    io = (R*)aligned_alloc(32, data_size * sizeof(R));
    is = (stride)aligned_alloc(32, vector_length * sizeof(INT));
    os = (stride)aligned_alloc(32, vector_length * sizeof(INT));

    for (size_t idx = 0; idx < data_size; ++idx) {
        ri[idx] = sin(idx * 0.01);
        ii[idx] = cos(idx * 0.01);
        ro[idx] = 0.0;
        io[idx] = 0.0;
    }

    for (INT idx = 0; idx < vector_length; ++idx) {
        is[idx] = (idx * 512) % 1024;
        os[idx] = (idx * 256) % 512;
    }

    v = data_size / vector_length;
    ivs = 1;
    ovs = 1;

    KP250000000 = 0.25;
    KP587785252 = sin(2.0 * M_PI * 1.0 / 5.0);
    KP951056516 = sin(2.0 * M_PI * 2.0 / 5.0);
    KP559016994 = -sin(2.0 * M_PI * 1.0 / 10.0);

    i = 0;
}