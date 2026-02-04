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
    // Variant 1: Consecutive memory access with pointer arithmetic
    // Assume xstride and ystride are 1; transform indexing to consecutive access via pointers
    const double *px = x;
    const double *py = y;
    for (i = 0; i < n; i++) {
        const double dx = *px - m_x;
        const double dy = *py - m_y;
        m_dx2 += (dx * dx - m_dx2) / (i + 1.);
        m_dxdy += (dx * dy - m_dxdy) / (i + 1.);
        px += xstride;
        py += ystride;
    }
}
