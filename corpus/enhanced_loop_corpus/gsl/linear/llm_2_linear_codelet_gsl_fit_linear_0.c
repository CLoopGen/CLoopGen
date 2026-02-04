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
    // Variant 1: Consecutive memory access by precomputing base pointers and using unit stride
    double *px = x;
    double *py = y;
    for (i = 0; i < n; i++) {
        m_x += (*px - m_x) / (i + 1.);
        m_y += (*py - m_y) / (i + 1.);
        px += xstride;
        py += ystride;
    }
}
