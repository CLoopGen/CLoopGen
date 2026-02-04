#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *x;
    double *w;
    int precomputed;
} gsl_integration_glfixed_table;

static double dummy_data_1[1024];
static double dummy_data_2[1024];

gsl_integration_glfixed_table glaw[200000];
size_t GLAWSIZE = 200000;
size_t n = 150000;
int i;
gsl_integration_glfixed_table *retval;

void init_vars() {
    for (size_t idx = 0; idx < GLAWSIZE; idx++) {
        glaw[idx].n = idx + 1;
        glaw[idx].x = dummy_data_1;
        glaw[idx].w = dummy_data_2;
        glaw[idx].precomputed = 1;
    }
}