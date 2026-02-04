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
    // Variant 2: Indirect (gather) access using an index array to simulate non-unit or irregular strides
    // This variant uses an auxiliary index array to access x and y elements, enabling arbitrary access patterns.
    size_t *indices = (size_t*)malloc(n * sizeof(size_t));
    if (!indices) return; // Handle allocation failure
    for (i = 0; i < n; i++) {
        indices[i] = i; // Base indices, could be randomized or reordered for more complex patterns
    }
    d2 = 0.0; // Initialize reduction variable
    for (i = 0; i < n; i++) {
        const size_t idx_x = indices[i] * xstride;
        const size_t idx_y = indices[i] * ystride;
        const double dx = x[idx_x] - m_x;
        const double dy = y[idx_y] - m_y;
        const double d = dy - b * dx;
        d2 += d * d;
    }
    free(indices);
}
