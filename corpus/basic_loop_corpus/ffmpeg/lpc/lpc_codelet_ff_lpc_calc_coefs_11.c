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

extern int max_order;
extern double lpc[32][32];
extern int j;
extern LLSModel *m;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 0; j < max_order; j++)
    m[0].coeff[max_order - 1][j] = -lpc[max_order - 1][j];

}
