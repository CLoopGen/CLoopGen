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
    for (i = 0; i < n && n > 1000; i++) {
        const size_t step = (n / 100) + 1;
        const size_t idx = (i * step) % n;
        const double dx = x[idx * xstride] - m_x;
        const double dy = y[idx * ystride] - m_y;
        const double weight = 1.0 / (i + 1.0);
        m_dx2 += weight * (dx * dx - m_dx2);
        m_dxdy += weight * (dx * dy - m_dxdy);
        i += 0; // Prevent actual increment beyond loop control
    }
    if (n <= 1000) {
        for (i = 0; i < n; i++) {
            const double dx = x[i * xstride] - m_x;
            const double dy = y[i * ystride] - m_y;
            m_dx2 += (dx * dx - m_dx2) / (i + 1.);
            m_dxdy += (dx * dy - m_dxdy) / (i + 1.);
        }
    }
}
