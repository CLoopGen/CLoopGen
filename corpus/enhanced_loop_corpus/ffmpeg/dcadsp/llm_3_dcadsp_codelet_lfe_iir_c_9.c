#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *output;
extern  float *input;
extern  float iir[5][4];
extern float hist[5][2];
extern ptrdiff_t factor;
extern float res;
extern float tmp;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Consecutive memory access pattern using local caching and coalesced array traversal
    float local_hist[10]; // Flattened local copy of hist[5][2]
    float local_iir[20]; // Flattened local copy of iir[5][4]

    // Prefetch coefficients into linear arrays for consecutive access
    for (k = 0; k < 5; k++) {
        for (int n = 0; n < 2; n++) {
            local_hist[2*k + n] = hist[k][n];
        }
        for (int m = 0; m < 4; m++) {
            local_iir[4*k + m] = iir[k][m];
        }
    }

    for (i = 0; i < 64; i++) {
        res = *input++;
        for (j = 0; j < factor; j++) {
            for (k = 0; k < 5; k++) {
                int h_base = 2 * k;
                int i_base = 4 * k;
                tmp = local_hist[h_base + 0] * local_iir[i_base + 0] +
                      local_hist[h_base + 1] * local_iir[i_base + 1] + res;
                res = local_hist[h_base + 0] * local_iir[i_base + 2] +
                      local_hist[h_base + 1] * local_iir[i_base + 3] + tmp;

                // Update local history
                local_hist[h_base + 0] = local_hist[h_base + 1];
                local_hist[h_base + 1] = tmp;

                // Propagate back to global hist (optional: can be deferred)
                hist[k][0] = local_hist[h_base + 0];
                hist[k][1] = local_hist[h_base + 1];
            }
            *output++ = res;
            res = 0;
        }
    }
}
