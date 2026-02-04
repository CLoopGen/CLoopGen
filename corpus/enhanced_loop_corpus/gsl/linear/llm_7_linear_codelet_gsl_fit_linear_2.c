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
    double prev_dx = 0.0;
    for (i = 0; i < n; i++) {
        const double dx = x[i * xstride] - m_x + prev_dx; // Introduce WAW and loop-carried dependency
        const double dy = y[i * ystride] - m_y;
        const double d = dy - b * dx;
        d2 += d * d;
        prev_dx = dx; // Carry dependency to next iteration
    }
}
