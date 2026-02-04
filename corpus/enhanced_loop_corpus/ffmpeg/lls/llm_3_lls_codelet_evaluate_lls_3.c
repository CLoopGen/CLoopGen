#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct LLSModel {
    double covariance[36][36] __attribute__((aligned(32)));
    double coeff[32][32] __attribute__((aligned(32)));
    double variance[32];
    int indep_count;
    void (*update_lls)(struct LLSModel *, const double *);
    double (*evaluate_lls)(struct LLSModel *, const double *, int);
} LLSModel;

extern LLSModel *m;
extern  double *param;
extern int order;
extern int i;
extern double out;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Mapping
    // Use an auxiliary index array to access param and coeff in a non-sequential,
    // indirect manner. This simulates scenarios with gather-style access.
    // We create a simple indirect permutation: reverse order of access.
    int indices[32];
    int n = order + 1;
    for (int j = 0; j < n; j++) {
        indices[j] = n - 1 - j;  // reversed access: from last to first
    }

    for (i = 0; i < n; i++) {
        int idx = indices[i];  // indirect index
        out += param[idx] * m->coeff[order][idx];
    }
}
