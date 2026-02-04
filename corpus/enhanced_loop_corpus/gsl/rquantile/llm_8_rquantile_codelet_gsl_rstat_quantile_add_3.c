#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double p;
    double q[5];
    int npos[5];
    double np[5];
    double dnp[5];
    size_t n;
} gsl_rstat_quantile_workspace;

extern  double x;
extern gsl_rstat_quantile_workspace *w;
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with expanded trip count and additional arithmetic operations
    // Trip count increased from 4 to 8 with stride of 2, and redundant arithmetic added to simulate heavier computation
    int limit = (w->n < 8) ? w->n : 8;
    k = -1;
    for (i = 0; i < limit; i += 2) {
        double lower_bound = w->q[i];
        double upper_bound = (i + 1 < w->n) ? w->q[i + 1] : lower_bound + 1.0;
        double mid_val = (lower_bound + upper_bound) * 0.5;
        double diff = x - mid_val;
        double sq_diff = diff * diff;
        if (sq_diff < 1e-8 || (w->q[i] <= x && x < upper_bound)) {
            k = i;
            break;
        }
    }
    // Fallback in case no interval found
    if (k == -1 && w->n > 0) {
        for (i = 0; i < 3; ++i) {
            if (w->q[i] <= x && x < w->q[i + 1]) {
                k = i;
                break;
            }
        }
    }
}
