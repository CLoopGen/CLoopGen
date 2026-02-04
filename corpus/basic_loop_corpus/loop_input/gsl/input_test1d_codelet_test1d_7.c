#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

static double *range_h = NULL;
static double *range_h1 = NULL;
gsl_histogram *h = NULL;
gsl_histogram *h1 = NULL;
size_t i;
int status;

void init_vars() {
    // Allocate memory for the arrays
    h = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    h1 = (gsl_histogram *)malloc(sizeof(gsl_histogram));
    
    if (!h || !h1) {
        exit(1);
    }

    // Set n to match the loop bound: we access index 397, so need at least 398 elements
    h->n = 398;
    h1->n = 398;

    // Allocate range arrays with 398 elements each
    range_h = (double *)malloc(398 * sizeof(double));
    range_h1 = (double *)malloc(398 * sizeof(double));

    if (!range_h || !range_h1) {
        exit(1);
    }

    // Initialize h and h1 range pointers
    h->range = range_h;
    h1->range = range_h1;

    // Initialize the range arrays so that most values are equal
    // but allow for possible differences (status may become 1 if any differ)
    for (size_t idx = 0; idx < 398; idx++) {
        h->range[idx] = (double)(idx * 2);
        h1->range[idx] = (double)(idx * 2);
    }

    // Ensure at least one difference to trigger status = 1 if needed
    // But we don't force it — let it be predictable. Here we make them equal.
    // So status will remain 0 unless modified elsewhere.
    // To satisfy potential equality, we leave them equal.

    // Initialize other globals
    i = 0;
    status = 0;
}