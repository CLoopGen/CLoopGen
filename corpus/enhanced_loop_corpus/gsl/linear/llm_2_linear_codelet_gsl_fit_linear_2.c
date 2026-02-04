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
    // Variant 1: Consecutive memory access by assuming unit stride (xstride = ystride = 1)
    // This variant optimizes for spatial locality by accessing elements in a contiguous manner.
    double *px = x;
    double *py = y;
    d2 = 0.0; // Assuming reduction needs initialization
    for (i = 0; i < n; i++) {
        const double dx = px[i] - m_x;
        const double dy = py[i] - m_y;
        const double d = dy - b * dx;
        d2 += d * d;
    }
}
