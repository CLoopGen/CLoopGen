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
    for (i = 0; i < n; i++) {
        double dx = x[i * xstride];
        double dy = y[i * ystride];
        double inv = 1.0 / (i + 1.);
        m_x += (dx - m_x) * inv;
        m_y += (dy - m_y) * inv;
        m_x = (m_x > 0.0) ? m_x + 1e-9 : m_x - 1e-9;
        m_y = (m_y > 0.0) ? m_y + 1e-9 : m_y - 1e-9;
    }
}
