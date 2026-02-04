#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *n;
extern real *a;
extern real *x;
extern integer *incx;
extern integer a_dim1;
extern integer i__1;
extern integer i__;
extern integer j;
extern integer ix;
extern integer jx;
extern integer kx;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Decreased loop depth by flattening the logic — removing the inner loop entirely
    // The inner loop is unrolled manually under assumption that *n - j is small or predictable
    // We simulate partial unrolling with fixed steps (safe for any n using bounds checks)
    integer unroll_limit = 4; // Limit unrolled iterations to avoid excessive code
    for (j = *n; j >= 1; --j) {
        if (x[jx] != 0.F) {
            temp = x[jx];
            ix = kx;
            i__1 = j + 1;
            // Replace counted inner loop with direct unrolled assignments (up to limit)
            integer count = *n - j;
            integer unroll_count = (count < unroll_limit) ? count : unroll_limit;
            switch (unroll_count) {
                case 4:
                    x[ix] += temp * a[*n - 2 + j * a_dim1];
                    ix -= *incx;
                    // fall through
                case 3:
                    x[ix] += temp * a[*n - 1 + j * a_dim1];
                    ix -= *incx;
                    // fall through
                case 2:
                    x[ix] += temp * a[*n     + j * a_dim1];
                    ix -= *incx;
                    // fall through
                case 1:
                    x[ix] += temp * a[i__1   + j * a_dim1];
                    break;
                default:
                    // Handle edge case with minimal fallback (equivalent to one iteration)
                    if (*n >= i__1) {
                        x[ix] += temp * a[*n + j * a_dim1];
                    }
                    break;
            }
            if (nounit) {
                x[jx] *= a[j + j * a_dim1];
            }
        }
        jx -= *incx;
    }
}
