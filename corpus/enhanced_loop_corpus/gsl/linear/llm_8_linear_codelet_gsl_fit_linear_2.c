#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *x;
extern  size_t xstride;
extern  double *y;
extern  size_t ystride;
extern  size_t n;
extern double m_x;
extern double m_y;
extern size_t i;
extern double d2;
extern double b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    for (i = 0; i < n; i += 2) {
        const size_t idx1 = i * xstride;
        const size_t idx2 = i * ystride;
        const double dx1 = x[idx1] - m_x;
        const double dy1 = y[idx2] - m_y;
        const double d1 = dy1 - b * dx1;
        d2 += d1 * d1;

        if (i + 1 < n) {
            const size_t idx1_next = (i + 1) * xstride;
            const size_t idx2_next = (i + 1) * ystride;
            const double dx2 = x[idx1_next] - m_x;
            const double dy2 = y[idx2_next] - m_y;
            const double d2_val = dy2 - b * dx2;
            d2 += d2_val * d2_val;
        }

        // Additional computation to increase arithmetic intensity
        d2 += dx1 * dx1 * 0.1;
    }
}
