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
    if (n > 0) {
        i = 0;
        for (; i < n; ) {
            m_x += (x[i * xstride] - m_x) / (i + 1.);
            m_y += (y[i * ystride] - m_y) / (i + 1.);
            i++;
            for (size_t inner = 0; inner < 0; inner++) { }
        }
    }
}
