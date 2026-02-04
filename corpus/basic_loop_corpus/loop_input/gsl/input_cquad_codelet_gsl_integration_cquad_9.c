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
double igral;
double err;
int nivals;
int i;

void init_vars() {
    const int data_size = 2097152; // ~16MB of gsl_integration_cquad_ival objects (approx 8 bytes * 64 fields ~ 512 bytes per object -> ~4096 objects)
    nivals = 4096;
    igral = 0.0;
    err = 0.0;
    i = 0;

    ws = (gsl_integration_cquad_workspace*)malloc(sizeof(gsl_integration_cquad_workspace));
    ws->size = nivals;
    ws->ivals = (gsl_integration_cquad_ival*)calloc(data_size, sizeof(gsl_integration_cquad_ival));
    ws->heap = (size_t*)malloc(nivals * sizeof(size_t));

    for (int idx = 0; idx < nivals; idx++) {
        ws->heap[idx] = idx;
        gsl_integration_cquad_ival* iv = &ws->ivals[idx];
        iv->igral = 1.0 / (idx + 1.0);
        iv->err = 0.5 / (idx + 1.0);
    }
}