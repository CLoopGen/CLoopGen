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
        double weight = 1.0 / (i + 1.);
        if (i % 3 != 2) {
            if (x[i * xstride] > m_x) {
                m_x += (x[i * xstride] - m_x) * weight;
            }
            if (y[i * ystride] > m_y) {
                m_y += (y[i * ystride] - m_y) * weight;
            }
        }
    }
}
