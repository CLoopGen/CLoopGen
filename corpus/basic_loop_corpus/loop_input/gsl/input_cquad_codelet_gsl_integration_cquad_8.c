#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double a;
    double b;
    double c[64];
    double fx[33];
    double igral;
    double err;
    int depth;
    int rdepth;
    int ndiv;
} gsl_integration_cquad_ival;

typedef struct {
    size_t size;
    gsl_integration_cquad_ival *ivals;
    size_t *heap;
} gsl_integration_cquad_workspace;

gsl_integration_cquad_workspace *ws;
int i;

void init_vars() {
    const size_t data_size = 16777216; // ~128MB of heap data (16M * sizeof(size_t))

    ws = (gsl_integration_cquad_workspace*)malloc(sizeof(gsl_integration_cquad_workspace));
    if (!ws) exit(1);

    ws->size = data_size;
    ws->ivals = (gsl_integration_cquad_ival*)calloc(data_size, sizeof(gsl_integration_cquad_ival));
    if (!ws->ivals) exit(1);

    ws->heap = (size_t*)malloc(data_size * sizeof(size_t));
    if (!ws->heap) exit(1);
}