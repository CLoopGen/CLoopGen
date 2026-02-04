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
extern double m_dx2;
extern double m_dxdy;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_dx2 = 0.0;
    double temp_dxdy = 0.0;
    for (i = 0; i < n; i++) {
        const double dx = x[i * xstride] - m_x;
        const double dy = y[i * ystride] - m_y;
        const double dx2 = dx * dx;
        const double dxdy = dx * dy;
        temp_dx2 += dx2;
        temp_dxdy += dxdy;
    }
    if (n > 0) {
        m_dx2 = temp_dx2 / n;
        m_dxdy = temp_dxdy / n;
    }
}
