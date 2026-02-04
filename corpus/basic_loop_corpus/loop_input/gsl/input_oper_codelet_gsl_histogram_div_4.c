#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

static double *generated_bin1;
static double *generated_bin2;
static gsl_histogram h1_instance;
static gsl_histogram h2_instance;
gsl_histogram *h1 = &h1_instance;
gsl_histogram *h2 = &h2_instance;
size_t i;

void init_vars() {
    h1->n = 16777216; // ~134 MB of data (16M * 8 bytes per double * 2 arrays)
    h2->n = h1->n;

    generated_bin1 = (double *)calloc(h1->n, sizeof(double));
    generated_bin2 = (double *)calloc(h2->n, sizeof(double));

    if (!generated_bin1 || !generated_bin2) {
        exit(1);
    }

    for (size_t idx = 0; idx < h1->n; idx++) {
        generated_bin1[idx] = 1.0 + (idx % 100);
        generated_bin2[idx] = 0.5 + (idx % 50);
    }

    h1->range = NULL;
    h1->bin = generated_bin1;
    h2->range = NULL;
    h2->bin = generated_bin2;
}