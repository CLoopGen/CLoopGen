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
    // Variant 1: Consecutive memory access by precomputing base pointers and using pointer arithmetic
    double *px = x;
    double *py = y;
    double sum_x = 0.0, sum_y = 0.0;
    for (i = 0; i < n; i++) {
        sum_x += px[0] - m_x;
        m_x += sum_x / (i + 1.);
        sum_y += py[0] - m_y;
        m_y += sum_y / (i + 1.);
        px += xstride;
        py += ystride;
    }
}
