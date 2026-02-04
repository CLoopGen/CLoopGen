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

gsl_rstat_quantile_workspace *w;
int i;

void init_vars() {
    w = (gsl_rstat_quantile_workspace*)calloc(1, sizeof(gsl_rstat_quantile_workspace));
    if (!w) exit(1);

    w->p = 0.5;
    for (int j = 0; j < 5; ++j) {
        w->q[j] = (double)(j + 1) * 0.1;
        w->npos[j] = j;
        w->np[j] = (double)(j + 1) * 10.0;
        w->dnp[j] = (double)(j + 1) * 0.5;
    }
    w->n = 5;
}