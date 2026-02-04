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
    igral = 0.0;
    err = 0.0;
    for (i = 0; i < nivals; i += 2) {
        size_t idx1 = ws->heap[i];
        igral += ws->ivals[idx1].igral;
        err += ws->ivals[idx1].err;
        if (i + 1 < nivals) {
            size_t idx2 = ws->heap[i + 1];
            igral += ws->ivals[idx2].igral;
            err += ws->ivals[idx2].err;
        }
    }
}
