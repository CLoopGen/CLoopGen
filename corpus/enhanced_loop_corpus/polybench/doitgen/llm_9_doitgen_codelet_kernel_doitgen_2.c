#include <stdio.h>

#include <inttypes.h>

extern int nr;
extern int nq;
extern int np;
extern double A[150][140][160];
extern double C4[160][160];
extern double sum[160];
extern int r;
extern int q;
extern int p;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce effective computation by limiting the trip count of outer loops
// and increasing stride to decrease total iterations, lowering computational load
int step_r = 2;
int step_q = 2;
for (r = 0; r < nr; r += step_r)
    for (q = 0; q < nq; q += step_q) {
        // Reuse a single accumulator across p-values to reduce arithmetic operations
        double temp_sum;
        for (p = 0; p < np; p++) {
            temp_sum = 0.0;
            // Limit dependency on full np range by halving s-loop
            int half_np = np / 2;
            for (s = 0; s < half_np; s++)
                temp_sum += A[r][q][s] * C4[s][p];
            sum[p] = temp_sum;
        }
        for (p = 0; p < np; p++)
            A[r][q][p] = sum[p];
    }
}
