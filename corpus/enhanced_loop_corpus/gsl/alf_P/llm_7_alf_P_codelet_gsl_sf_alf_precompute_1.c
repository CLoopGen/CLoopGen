#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t lmax;
extern  size_t mmax;
extern double *alm;
extern double *sqrts;
extern size_t l;
extern size_t m;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (m = 1; m <= mmax; ++m) {
        k += 2;
        size_t base_k = k;
        // Unroll the inner loop by factor of 2 to modify data dependencies and expose parallelism
        l = m + 2;
        // Handle odd number of iterations safely with cleanup
        size_t trip_count = (lmax >= l) ? (lmax - l + 1) : 0;
        size_t unrolled_count = trip_count / 2;

        for (size_t u = 0; u < unrolled_count; ++u) {
            size_t curr_l1 = l + 2*u;
            size_t curr_l2 = l + 2*u + 1;
            size_t idx1 = 2 * (base_k + 2*u);
            size_t idx2 = 2 * (base_k + 2*u + 1);

            // Compute both iterations independently to reduce loop-carried WAW and WAR hazards
            alm[idx1] = ((2. * curr_l1 - 1.) / sqrts[curr_l1 + m]) / sqrts[curr_l1 - m];
            alm[idx1 + 1] = -(sqrts[curr_l1 + m - 1] / sqrts[curr_l1 + m]) * (sqrts[curr_l1 - m - 1] / sqrts[curr_l1 - m]);

            alm[idx2] = ((2. * curr_l2 - 1.) / sqrts[curr_l2 + m]) / sqrts[curr_l2 - m];
            alm[idx2 + 1] = -(sqrts[curr_l2 + m - 1] / sqrts[curr_l2 + m]) * (sqrts[curr_l2 - m - 1] / sqrts[curr_l2 - m]);
        }

        // Handle remaining iteration if trip_count is odd
        if (trip_count % 2 == 1) {
            size_t last_l = l + 2 * unrolled_count;
            size_t last_idx = 2 * (base_k + 2 * unrolled_count);
            alm[last_idx] = ((2. * last_l - 1.) / sqrts[last_l + m]) / sqrts[last_l - m];
            alm[last_idx + 1] = -(sqrts[last_l + m - 1] / sqrts[last_l + m]) * (sqrts[last_l - m - 1] / sqrts[last_l - m]);
        }

        k = base_k + trip_count; // Update k after full inner loop
    }
}
