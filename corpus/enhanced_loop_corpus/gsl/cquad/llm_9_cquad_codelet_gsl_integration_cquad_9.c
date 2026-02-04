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
    double local_igral = 0.0;
    double local_err = 0.0;
    int stride = 4;
    for (i = 0; i < nivals; i++) {
        gsl_integration_cquad_ival *ival = &ws->ivals[ws->heap[i]];
        local_igral += ival->igral;
        local_err += ival->err;
        for (int j = 0; j < 8; j++) {
            local_igral += ival->c[j] * ival->c[j];
            local_err += ival->fx[j] * ival->fx[j];
        }
    }
    igral += local_igral;
    err += local_err;
}
