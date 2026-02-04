#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t limit;
    size_t size;
    size_t nrmax;
    size_t i;
    size_t maximum_level;
    double *alist;
    double *blist;
    double *rlist;
    double *elist;
    size_t *order;
    size_t *level;
} gsl_integration_workspace;

gsl_integration_workspace *workspace;
double errsum;
double abserr0;
size_t nint;
size_t *ndin;
size_t i;

void init_vars() {
    nint = 1 << 24; // ~16.7 million elements, aiming for ~0.01 sec runtime
    abserr0 = 1.5;

    workspace = (gsl_integration_workspace*)malloc(sizeof(gsl_integration_workspace));
    workspace->limit = nint;
    workspace->size = nint;
    workspace->nrmax = 16;
    workspace->i = 0;
    workspace->maximum_level = 10;

    workspace->elist = (double*)calloc(nint, sizeof(double));
    workspace->alist = (double*)malloc(nint * sizeof(double));
    workspace->blist = (double*)malloc(nint * sizeof(double));
    workspace->rlist = (double*)malloc(nint * sizeof(double));
    workspace->order = (size_t*)malloc(nint * sizeof(size_t));
    workspace->level = (size_t*)malloc(nint * sizeof(size_t));

    ndin = (size_t*)malloc(nint * sizeof(size_t));
    
    for (size_t idx = 0; idx < nint; idx++) {
        ndin[idx] = (idx % 3) == 0 ? 1 : 0; // Sparse trigger pattern
        workspace->order[idx] = idx;
        workspace->level[idx] = idx % 10;
        workspace->alist[idx] = (double)(idx + 1);
        workspace->blist[idx] = (double)(2 * idx + 1);
        workspace->rlist[idx] = (double)(idx % 1000) * 0.001;
    }

    errsum = 0.0;
    i = 0;
}