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
    // Variant 2: Strided access with reversed iteration order (backward traversal) using index scaling
    for (i = n; i > 0; i--) {
        size_t idx = (i - 1) * xstride;
        size_t idy = (i - 1) * ystride;
        m_x += (x[idx] - m_x) / i;
        m_y += (y[idy] - m_y) / i;
    }
}
