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

extern gsl_integration_cquad_workspace *ws;
extern double igral;
extern double err;
extern int nivals;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive (direct) access by reordering heap to enable sequential memory access
    // Assume ws->heap is pre-sorted such that accesses to ivals are in increasing order for better locality
    gsl_integration_cquad_ival *ivals = ws->ivals;
    size_t *heap = ws->heap;
    double local_igral = 0.0;
    double local_err = 0.0;
    for (i = 0; i < nivals; i++) {
        int idx = heap[i];
        local_igral += ivals[idx].igral;
        local_err += ivals[idx].err;
    }
    igral += local_igral;
    err += local_err;
}
