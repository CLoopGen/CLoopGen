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
    for (i = 0; i < n; i += 2) {
        const double dx1 = x[i * xstride] - m_x;
        const double dy1 = y[i * ystride] - m_y;
        const double d1 = (m_y - b * m_x) + dy1 - b * dx1;
        d2 += d1 * d1;

        if (i + 1 < n) {
            const double dx2 = x[(i + 1) * xstride] - m_x;
            const double dy2 = y[(i + 1) * ystride] - m_y;
            const double d2_val = (m_y - b * m_x) + dy2 - b * dx2;
            d2 += d2_val * d2_val;
        }
    }
}
