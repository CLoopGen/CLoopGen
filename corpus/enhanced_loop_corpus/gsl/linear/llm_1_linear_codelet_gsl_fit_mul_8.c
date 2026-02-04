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
if (n > 0) {
    for (i = 0; i < n; i += 2) {
        const size_t limit = (i + 1 < n) ? i + 2 : i + 1;
        for (size_t k = i; k < limit; k++) {
            const double dx = x[k * xstride] - m_x;
            const double dy = y[k * ystride] - m_y;
            const double d = (m_y - b * m_x) + dy - b * dx;
            d2 += d * d;
        }
    }
}
}
