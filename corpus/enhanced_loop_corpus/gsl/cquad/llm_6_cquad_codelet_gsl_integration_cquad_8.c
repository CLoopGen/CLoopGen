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
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t size = ws->size;
    size_t *heap = ws->heap;
    for (i = 0; i < size; i++) {
        heap[i] = i;
        if (i > 0) {
            heap[i] += heap[i - 1]; // Introduce RAW dependency: each iteration depends on previous write
        }
    }
}
