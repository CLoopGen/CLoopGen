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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            m_x += (x[i * xstride] - m_x) / (i + 1.);
            m_x += (x[(i + 1) * xstride] - m_x) / (i + 2.);
            m_y += (y[i * ystride] - m_y) / (i + 1.);
            m_y += (y[(i + 1) * ystride] - m_y) / (i + 2.);
        } else {
            m_x += (x[i * xstride] - m_x) / (i + 1.);
            m_y += (y[i * ystride] - m_y) / (i + 1.);
        }
    }
}
