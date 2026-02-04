#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t nx;
    size_t ny;
    double *xrange;
    double *yrange;
    double *bin;
} gsl_histogram2d;

static double *xrange_data;
static double *yrange_data;
static double *bin_data;
gsl_histogram2d *hr;
size_t i;

void init_vars() {
    // Allocate data to make the loop take ~0.01 seconds
    // The loop runs 11 iterations (i=0 to 10), so we need to set nx >= 11
    // To get appropriate data size, we allocate more memory than accessed
    const size_t total_size = 16 * 1024 * 1024; // ~16 MB of double data
    const size_t num_doubles = total_size / sizeof(double);
    
    // Ensure we have enough space for the loop index
    if (num_doubles < 11) {
        xrange_data = (double*)calloc(11, sizeof(double));
        yrange_data = (double*)calloc(11, sizeof(double));
        bin_data = (double*)calloc(num_doubles, sizeof(double));
    } else {
        xrange_data = (double*)calloc(num_doubles, sizeof(double));
        yrange_data = (double*)calloc(num_doubles, sizeof(double));
        bin_data = (double*)calloc(num_doubles, sizeof(double));
    }
    
    hr = (gsl_histogram2d*)malloc(sizeof(gsl_histogram2d));
    hr->nx = num_doubles > 11 ? num_doubles : 11;
    hr->ny = num_doubles;
    hr->xrange = xrange_data;
    hr->yrange = yrange_data;
    hr->bin = bin_data;
    
    i = 0;
}