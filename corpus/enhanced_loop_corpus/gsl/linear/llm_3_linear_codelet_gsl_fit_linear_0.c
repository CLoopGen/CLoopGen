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
    // Variant 2: Indirect memory access using an index array to simulate irregular access pattern
    size_t *indices = (size_t*)malloc(n * sizeof(size_t));
    if (!indices) return; // Handle allocation failure
    for (size_t j = 0; j < n; j++) {
        indices[j] = j * xstride; // Store precomputed indices
    }
    for (i = 0; i < n; i++) {
        size_t idx = indices[i];
        m_x += (x[idx] - m_x) / (i + 1.);
        m_y += (y[idx] - m_y) / (i + 1.);
    }
    free(indices);
}
