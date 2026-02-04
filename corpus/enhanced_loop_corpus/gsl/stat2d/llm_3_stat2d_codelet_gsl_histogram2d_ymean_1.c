#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t nx;
    size_t ny;
    double *xrange;
    double *yrange;
    double *bin;
} gsl_histogram2d;

extern  gsl_histogram2d *h;
extern  size_t nx;
extern  size_t ny;
extern size_t i;
extern size_t j;
extern long double wmean;
extern long double W;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect array access using index arrays to simulate irregular memory access pattern
    size_t *index_map = (size_t*)malloc(nx * sizeof(size_t));
    if (!index_map) return; // Handle allocation failure
    for (i = 0; i < nx; i++) {
        index_map[i] = i;  // Identity map, but allows for future non-consecutive patterns (e.g., randomized indices)
    }
    for (j = 0; j < ny; j++) {
        double yj = (h->yrange[j + 1] + h->yrange[j]) / 2.0;
        double wj = 0;
        for (i = 0; i < nx; i++) {
            size_t idx = index_map[i] * ny + j;  // Use indirect indexing for bin access
            double wij = h->bin[idx];
            if (wij > 0)
                wj += wij;
        }
        if (wj > 0) {
            W += wj;
            wmean += (yj - wmean) * (wj / W);
        }
    }
    free(index_map);
}
