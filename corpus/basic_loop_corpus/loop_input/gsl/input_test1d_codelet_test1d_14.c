#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

static double h1_bin_data[397];
static double h1_range_data[398]; // n+1 elements for range
static double g_bin_data[397];
static double g_range_data[398];

static gsl_histogram h1_instance = {397, h1_range_data, h1_bin_data};
static gsl_histogram g_instance = {397, g_range_data, g_bin_data};

gsl_histogram *h1 = &h1_instance;
gsl_histogram *g = &g_instance;
size_t i;
int status;

void init_vars() {
    for (i = 0; i < 397; i++) {
        g_bin_data[i] = (double)(i % 17) * 0.05;
        h1_bin_data[i] = 0.25 + g_bin_data[i] + ((i % 31) == 0 ? 0.01 : 0.0);
    }
    for (i = 0; i < 398; i++) {
        h1_range_data[i] = (double)i * 0.5;
        g_range_data[i] = (double)i * 0.5;
    }
    i = 0;
    status = 0;
}