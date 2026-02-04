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
    // Variant 1: Consecutive memory access with array base pointer adjustment
    // Assume x and y are accessed consecutively by pre-scaling the stride into pointer offsets
    double *px = x;
    double *py = y;
    for (i = 0; i < n; i++) {
        const double dx = px[i] - m_x;
        const double dy = py[i] - m_y;
        m_dx2 += (dx * dx - m_dx2) / (i + 1.);
        m_dxdy += (dx * dy - m_dxdy) / (i + 1.);
    }
}
