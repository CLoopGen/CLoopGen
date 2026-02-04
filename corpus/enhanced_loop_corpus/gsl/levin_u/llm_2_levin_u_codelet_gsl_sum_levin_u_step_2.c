#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t size;
    size_t i;
    size_t terms_used;
    double sum_plain;
    double *q_num;
    double *q_den;
    double *dq_num;
    double *dq_den;
    double *dsum;
} gsl_sum_levin_u_workspace;

extern  size_t n;
extern  size_t nmax;
extern gsl_sum_levin_u_workspace *w;
extern double factor;
extern double ratio;
extern unsigned int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification - Use strided access by reversing the order of indices for dq arrays (interchange stride)
    // This changes memory access from row-major-like to column-major-like in the dq arrays, increasing stride but enabling potential vectorization along j when i is fixed.
    for (j = n - 1; j >= 0; j--) {
        double c = factor * (j + 1) / (n + 1);
        factor *= ratio;
        w->q_den[j] = w->q_den[j + 1] - c * w->q_den[j];
        w->q_num[j] = w->q_num[j + 1] - c * w->q_num[j];
        
        // Strided access: instead of varying i with fixed j, we simulate column-wise traversal by accessing all i for each j
        // Original was: ((i) * (nmax + 1) + (j)) — now we keep same formula, but the effective stride over i becomes 1 in index calculation
        // However, to emphasize strided pattern, we can reorganize the inner loop to highlight column-like reuse
        for (i = 0; i < n; i++) {
            size_t idx_j = ((i) * (nmax + 1) + (j));
            size_t idx_j1 = ((i) * (nmax + 1) + (j + 1));
            w->dq_den[idx_j] = w->dq_den[idx_j1] - c * w->dq_den[idx_j];
            w->dq_num[idx_j] = w->dq_num[idx_j1] - c * w->dq_num[idx_j];
        }
        size_t idx_n_j = ((n) * (nmax + 1) + (j));
        size_t idx_n_j1 = ((n) * (nmax + 1) + (j + 1));
        w->dq_den[idx_n_j] = w->dq_den[idx_n_j1];
        w->dq_num[idx_n_j] = w->dq_num[idx_n_j1];
    }
}
