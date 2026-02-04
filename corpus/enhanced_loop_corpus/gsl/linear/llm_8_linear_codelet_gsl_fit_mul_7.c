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
    for (i = 0; i < n; i += 2) {
        const double dx1 = x[i * xstride] - m_x;
        const double dy1 = y[i * ystride] - m_y;
        const double dx1_sq = dx1 * dx1;
        const double dxdy1 = dx1 * dy1;
        m_dx2 += (dx1_sq - m_dx2) / (i + 1.);
        m_dxdy += (dxdy1 - m_dxdy) / (i + 1.);

        if (i + 1 < n) {
            const double dx2 = x[(i + 1) * xstride] - m_x;
            const double dy2 = y[(i + 1) * ystride] - m_y;
            const double dx2_sq = dx2 * dx2;
            const double dxdy2 = dx2 * dy2;
            m_dx2 += (dx2_sq - m_dx2) / (i + 2.);
            m_dxdy += (dxdy2 - m_dxdy) / (i + 2.);
        }
    }
}
