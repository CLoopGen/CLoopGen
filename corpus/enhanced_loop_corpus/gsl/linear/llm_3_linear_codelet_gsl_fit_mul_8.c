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
    // Variant 2: Indirect (Indexed) Memory Access
    // Use an index array to access x and y elements in a non-sequential order
    // Simulates access via indices, e.g., gathered from sorting or permutation
    // Here we simulate a simple indirect pattern using an index map: idx[i] = i * 2 % n
    // Ensures all accesses stay within bounds [0, n)
    size_t *idx = (size_t*)malloc(n * sizeof(size_t));
    if (!idx) return; // Handle allocation failure
    for (size_t j = 0; j < n; j++) {
        idx[j] = (j * 2) % n; // Example permutation: every second element, wrap around
    }
    for (i = 0; i < n; i++) {
        const size_t k = idx[i]; // Indirect indexing
        const double dx = x[k * xstride] - m_x;
        const double dy = y[k * ystride] - m_y;
        const double d = (m_y - b * m_x) + dy - b * dx;
        d2 += d * d;
    }
    free(idx);
}
