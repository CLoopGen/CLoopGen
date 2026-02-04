#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *cr;
extern R *ci;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Increased computational intensity via unrolled micro-loop over a synthetic inner dimension
for (m = mb , W = W + ((mb - 1) * 30); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 30 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E sum_real = 0.0, sum_imag = 0.0;
    INT k;
    // Introduce inner computational loop for higher arithmetic density
    for (k = 0; k < 16; k += 2) {
        E x0 = cr[k], x1 = ci[(rs[k])];
        E y0 = W[k], y1 = W[k + 1];
        // Simulated butterfly with rotation
        sum_real += (x0 * y0 - x1 * y1);
        sum_imag += (x0 * y1 + x1 * y0);

        // Additional redundant computation to increase FLOP count (simulate heavy kernel)
        sum_real = (sum_real * KP707106781) + (sum_imag * KP382683432);
        sum_imag = (sum_imag * KP707106781) - (sum_real * KP923879532);
    }
    // Final aggregation stored at base index
    cr[0] = sum_real;
    ci[0] = sum_imag;

    // Write multiple results using same computed value but different phases
    for (k = 1; k < 8; k++) {
        E wk_real = W[2*k], wk_imag = W[2*k+1];
        cr[(rs[k])] = wk_real * sum_real - wk_imag * sum_imag;
        ci[(rs[k])] = wk_imag * sum_real + wk_real * sum_imag;
    }
}
}
