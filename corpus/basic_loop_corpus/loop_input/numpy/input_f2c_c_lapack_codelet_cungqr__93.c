#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer kk;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // Based on typical performance, aim for moderate matrix size
    a_dim1 = 1024;  // leading dimension
    kk = 512;
    i__1 = a_dim1;  // j goes from kk+1 to i__1

    // Allocate 2D array as a single block: [a_dim1][a_dim1] roughly
    a = (singlecomplex*)aligned_alloc(32, sizeof(singlecomplex) * a_dim1 * a_dim1);
    if (!a) {
        exit(1);
    }

    // Ensure loop bounds are safe:
    // j from kk+1 to i__1 => 513 to 1024
    // i__ from 1 to kk => 1 to 512
    // index: i__ + j*a_dim1 must be < a_dim1*a_dim1
    // max index: 512 + 1024*1024 = 512 + 1048576 = 1049088 < 1048576? -> no!
    // So we must reduce dimensions to prevent overflow

    // Adjust: make a_dim1 larger than max j index
    // Let's re-tune: use smaller logical sizes but keep allocation large enough
    a_dim1 = 2048;
    kk = 1000;
    i__1 = 2000;  // j from 1001 to 2000

    free(a); // free previous
    a = (singlecomplex*)aligned_alloc(32, sizeof(singlecomplex) * a_dim1 * a_dim1);
    if (!a) {
        exit(1);
    }

    // Final safe bounds:
    // max index = i__ + j*a_dim1 <= kk + i__1*a_dim1 = 1000 + 2000*2048 = 1000 + 4,096,000 = 4,097,000
    // allocated size = 2048*2048 = 4,194,304 > 4,097,000 -> safe
}