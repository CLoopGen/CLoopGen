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
size_t nint;
size_t i;

void init_vars() {
    nint = 134217728;  // ~1024 MB of size_t data (each size_t is 8 bytes, array of 134M elements ~1024MB)

    workspace = (gsl_integration_workspace*)calloc(1, sizeof(gsl_integration_workspace));
    if (!workspace) exit(1);

    workspace->limit = nint;
    workspace->size = 0;
    workspace->nrmax = 32;
    workspace->i = 0;
    workspace->maximum_level = 10;

    workspace->alist = (double*)calloc(nint, sizeof(double));
    workspace->blist = (double*)calloc(nint, sizeof(double));
    workspace->rlist = (double*)calloc(nint, sizeof(double));
    workspace->elist = (double*)calloc(nint, sizeof(double));
    workspace->order = (size_t*)calloc(nint, sizeof(size_t));
    workspace->level = (size_t*)calloc(nint, sizeof(size_t));

    if (!workspace->alist || !workspace->blist || !workspace->rlist || 
        !workspace->elist || !workspace->order || !workspace->level) {
        exit(1);
    }
}