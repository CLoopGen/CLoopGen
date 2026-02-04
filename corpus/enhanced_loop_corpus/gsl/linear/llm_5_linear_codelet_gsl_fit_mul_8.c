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
    d2 = 0.0;
    for (i = 0; i < n; i++) {
        const double dx = x[i * xstride] - m_x;
        const double dy = y[i * ystride] - m_y;
        const double d = (m_y - b * m_x) + dy - b * dx;
        if (!(dx < 1e-8 && dx > -1e-8)) {
            d2 += d * d;
        }
    }
}
