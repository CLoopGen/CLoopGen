#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *Rp = NULL;
R *Ip = NULL;
R *Rm = NULL;
R *Im = NULL;
R *W = NULL;
stride rs = NULL;
INT mb = 0;
INT me = 0;
INT ms = 0;
E KP500000000 = 0.5;
E KP866025403 = 0.8660254037844386; // approx sqrt(3)/2
INT m = 0;

static R *alloc_aligned_array(size_t n) {
    void *ptr;
    if (posix_memalign(&ptr, 32, n * sizeof(R)) != 0) {
        exit(1);
    }
    return (R*)ptr;
}

void init_vars() {
    const size_t total_data_size = 1 << 24; // ~16MB of doubles (about 128MB in bytes)
    const size_t N = total_data_size / (4 * sizeof(R)); // Four arrays: Rp, Ip, Rm, Im
    const INT vector_length = 3;
    const INT W_stride = 10;

    Rp = alloc_aligned_array(N * vector_length);
    Ip = alloc_aligned_array(N * vector_length);
    Rm = alloc_aligned_array(N * vector_length);
    Im = alloc_aligned_array(N * vector_length);
    W = alloc_aligned_array(N * W_stride);

    rs = (stride)malloc(N * sizeof(INT));
    if (!rs) exit(1);

    for (INT i = 0; i < N; ++i) {
        rs[i] = (i % (vector_length - 1)) + 1; // ensure rs[1], rs[2] are valid indices within [1,2]
    }

    for (size_t i = 0; i < N * vector_length; ++i) {
        Rp[i] = (R)(rand() % 1000) / 100.0;
        Ip[i] = (R)(rand() % 1000) / 100.0;
        Rm[i] = (R)(rand() % 1000) / 100.0;
        Im[i] = (R)(rand() % 1000) / 100.0;
    }

    for (size_t i = 0; i < N * W_stride; ++i) {
        W[i] = (R)(rand() % 1000) / 1000.0;
    }

    mb = 1;
    me = N;
    ms = vector_length;
}