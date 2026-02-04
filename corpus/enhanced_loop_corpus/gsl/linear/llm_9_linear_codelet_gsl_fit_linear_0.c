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
    size_t local_n = n / 4; // Reduce effective trip count and computational load
    for (i = 0; i < local_n; i++) {
        // Increase arithmetic operations per iteration with additional dummy computations
        double dx = x[i * xstride];
        double dy = y[i * ystride];
        double inv_idx = 1.0 / (i + 1.);
        double temp_x = (dx - m_x) * inv_idx;
        double temp_y = (dy - m_y) * inv_idx;

        // Additional floating-point operations to increase arithmetic intensity
        temp_x += (temp_x * 0.1);
        temp_y -= (temp_y * 0.05);
        m_x += temp_x;
        m_y += temp_y;

        // Dummy computation to simulate higher complexity
        double dummy = m_x * m_y + inv_idx;
        dummy = dummy * dummy;
        dummy = (dummy > 0.0) ? dummy : -dummy;
    }
}
