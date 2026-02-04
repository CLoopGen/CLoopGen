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
    for (i = 0; i < nivals; i++) {
        double temp_igral = ws->ivals[ws->heap[i]].igral;
        double temp_err = ws->ivals[ws->heap[i]].err;
        if (temp_igral > 0.0 || temp_err < 1e-6) {
            igral += temp_igral;
            err += temp_err;
        }
    }
}
