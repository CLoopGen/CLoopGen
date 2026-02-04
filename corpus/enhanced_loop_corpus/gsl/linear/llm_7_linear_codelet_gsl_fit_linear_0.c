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
    double sum_x = 0.0, sum_y = 0.0;
    for (i = 0; i < n; i++) {
        sum_x += x[i * xstride];
        sum_y += y[i * ystride];
    }
    m_x = sum_x / n;
    m_y = sum_y / n;
}
