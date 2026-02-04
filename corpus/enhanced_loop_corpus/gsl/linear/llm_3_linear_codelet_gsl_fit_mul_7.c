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
    // Variant 2: Strided access with reversed traversal order (backward striding)
    // Access elements from the end to the beginning using the original stride
    for (i = 0; i < n; i++) {
        const size_t idx = (n - 1 - i); // Reverse index
        const double dx = x[idx * xstride] - m_x;
        const double dy = y[idx * ystride] - m_y;
        m_dx2 += (dx * dx - m_dx2) / (i + 1.);
        m_dxdy += (dx * dy - m_dxdy) / (i + 1.);
    }
}
