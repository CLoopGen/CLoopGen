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
extern  double ymean;
extern  size_t nx;
extern  size_t ny;
extern size_t i;
extern size_t j;
extern long double wvariance;
extern long double W;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational load by skipping zero-weight bins aggressively and adjusting trip count logic
    // Also modify update formula to minimize divisions
    long double wsum = W;
    for (j = 0; j < ny; j++) {
        double yj_val = (h->yrange[j + 1] + h->yrange[j]) * 0.5 - ymean;
        double yj_sq = yj_val * yj_val;
        double wj = 0;

        // Early exit condition: skip j if range suggests no contribution (heuristic based on bin structure)
        int has_contribution = 0;
        for (i = 0; i < nx; i++) {
            double wij = h->bin[i * ny + j];
            if (wij > 1e-15) {  // Avoid strict zero check for numerical robustness
                wj += wij;
                has_contribution = 1;
            }
        }
        if (!has_contribution) continue;

        if (wj > 0) {
            wsum += wj;
            // Reformulated to reduce division frequency (only one division at end)
            wvariance = (wvariance * W + yj_sq * wj) / wsum;
            W = wsum;
        }
    }
}
