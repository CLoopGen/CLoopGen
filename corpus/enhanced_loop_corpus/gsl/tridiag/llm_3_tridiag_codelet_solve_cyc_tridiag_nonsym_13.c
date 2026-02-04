#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double abovediag[];
extern size_t a_stride;
extern double x[];
extern size_t x_stride;
extern size_t N;
extern double *alpha;
extern double *zb;
extern double *zu;
extern double *w;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing using pointer arithmetic
    // Introduce base pointers and stride-based progression to simulate irregular but predictable access
    // This variant uses pointer arithmetic to traverse arrays with explicit strides

    double *w_ptr = w + N - 2;
    double *zu_ptr = zu + N - 2;
    double *abovediag_ptr = abovediag + a_stride * (N - 2);
    double *alpha_ptr = alpha + N - 2;
    double *zb_ptr = zb + N - 2;
    double *x_ptr = x + x_stride * (N - 2);

    for (size_t step = 0; step <= N - 2; step++, w_ptr--, zu_ptr--, abovediag_ptr -= a_stride, alpha_ptr--, zb_ptr--, x_ptr -= x_stride) {
        *(w_ptr) = (*zu_ptr - *(abovediag_ptr) * *(w_ptr + 1)) / *alpha_ptr;
        *x_ptr = (*zb_ptr - *(abovediag_ptr) * *(x_ptr + x_stride)) / *alpha_ptr;
    }
}
