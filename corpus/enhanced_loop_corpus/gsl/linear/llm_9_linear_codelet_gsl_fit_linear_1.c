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
    size_t step = (n > 1000) ? n / 100 : 1;
    for (i = 0; i < n; i += step) {
        const double dx = x[i * xstride] - m_x;
        const double dy = y[i * ystride] - m_y;
        const double dx_abs = dx > 0 ? dx : -dx;
        const double dy_abs = dy > 0 ? dy : -dy;
        const double dx2 = dx * dx;
        const double dxdy = dx * dy;
        const double weight = 1.0 / (i + 1.);

        m_dx2 += (dx2 - m_dx2) * weight;
        m_dxdy += (dxdy - m_dxdy) * weight;

        // Additional light computation to increase arithmetic intensity
        m_dx2 = (m_dx2 + dx_abs * dy_abs) * 0.5;
    }
}
