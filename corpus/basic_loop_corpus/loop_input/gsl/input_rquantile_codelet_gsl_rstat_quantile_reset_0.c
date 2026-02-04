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

static gsl_rstat_quantile_workspace w_instance;
gsl_rstat_quantile_workspace *w = &w_instance;
size_t i;

void init_vars() {
    w = &w_instance;
    w->n = 5;
    for (size_t j = 0; j < 5; ++j) {
        w->q[j] = 0.0;
        w->np[j] = 0.0;
        w->dnp[j] = 0.0;
        w->npos[j] = 0;
    }
    w->p = 0.0;
}