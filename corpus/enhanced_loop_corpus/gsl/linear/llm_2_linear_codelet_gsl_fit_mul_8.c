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
    // Variant 1: Consecutive Memory Access (assuming stride = 1)
    // We assume xstride and ystride are 1 for consecutive access
    // This improves cache locality when data is densely packed
    const size_t xs = xstride;
    const size_t ys = ystride;
    double *px = x;
    double *py = y;
    for (i = 0; i < n; i++) {
        const double dx = px[i * xs] - m_x;
        const double dy = py[i * ys] - m_y;
        const double d = (m_y - b * m_x) + dy - b * dx;
        d2 += d * d;
    }
}
