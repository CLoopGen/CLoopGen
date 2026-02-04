#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *cr;
R *ci;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP866025403 = 0.8660254037844386; // Approximation of sqrt(3)/2
E KP500000000 = 0.5;
INT m;

static size_t data_size = 1 << 24; // ~16 million elements, approx 128MB for doubles
static size_t max_stride = 1024;

void init_vars() {
    // Allocate memory
    cr = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    ci = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));
    W = (R*)aligned_alloc(sizeof(R), data_size * sizeof(R));

    if (!cr || !ci || !W) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize arrays with meaningful values
    for (size_t i = 0; i < data_size; i++) {
        cr[i] = (R)(rand()) / RAND_MAX;
        ci[i] = (R)(rand()) / RAND_MAX;
        W[i] = (R)(rand()) / RAND_MAX;
    }

    // Allocate and initialize stride array
    rs = (INT*)malloc(max_stride * sizeof(INT));
    if (!rs) {
        fprintf(stderr, "Stride allocation failed\n");
        exit(1);
    }

    // Set up strides: ensure valid access within allocated range
    for (INT i = 0; i < max_stride; i++) {
        rs[i] = ((i + 1) * 17) % (data_size / 8); // Keep offsets safe
    }

    // Set loop bounds to ensure no out-of-bounds access
    ms = 1;
    mb = 1;
    me = (data_size / 8) - 1; // Conservative bound to prevent overflow in indexing

    // Ensure that during loop:
    // - m goes from mb to me-1
    // - W is accessed at +0, +1, +2, +3 -> needs at least (me-mb)*4 elements
    // - rs[1], rs[2] are used -> need rs of size >=3
    // - cr and ci indexed via rs[1], rs[2] -> those must be < data_size

    if (me - mb > data_size / 4) {
        me = data_size / 4;
    }
}