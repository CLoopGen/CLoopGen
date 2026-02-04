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
int k;

void init_vars() {
    w = (gsl_rstat_quantile_workspace*)calloc(1, sizeof(gsl_rstat_quantile_workspace));
    if (!w) exit(1);

    w->n = 5;

    k = 0;
}