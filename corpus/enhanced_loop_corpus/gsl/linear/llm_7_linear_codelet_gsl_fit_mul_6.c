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
    double prev_m_x = m_x;
    double prev_m_y = m_y;
    for (i = 0; i < n; i++) {
        double dx = x[i * xstride] - prev_m_x;
        double dy = y[i * ystride] - prev_m_y;
        m_x = prev_m_x + dx / (i + 1.);
        m_y = prev_m_y + dy / (i + 1.);
        prev_m_x = m_x;
        prev_m_y = m_y;
    }
}
