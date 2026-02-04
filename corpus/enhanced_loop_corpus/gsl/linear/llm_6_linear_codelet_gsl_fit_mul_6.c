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
    double temp_x = m_x;
    double temp_y = m_y;
    for (i = 0; i < n; i++) {
        temp_x += (x[i * xstride] - temp_x) / (i + 1.);
        temp_y += (y[i * ystride] - temp_y) / (i + 1.);
    }
    m_x = temp_x;
    m_y = temp_y;
}
