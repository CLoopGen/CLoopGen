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
    size_t j, k;
    const size_t factor = 16;
    const size_t unrolled_n = (n / factor) * factor;

    for (j = 0; j < unrolled_n; j += factor) {
        double local_d2 = 0.0;
        for (k = 0; k < factor; k++) {
            const size_t idx = j + k;
            const double dx = x[idx * xstride] - m_x;
            const double dy = y[idx * ystride] - m_y;
            const double d = dy - b * dx;
            local_d2 += d * d;
        }
        d2 += local_d2;
    }

    for (; j < n; j++) {
        const double dx = x[j * xstride] - m_x;
        const double dy = y[j * ystride] - m_y;
        const double d = dy - b * dx;
        d2 += d * d;
    }
}
