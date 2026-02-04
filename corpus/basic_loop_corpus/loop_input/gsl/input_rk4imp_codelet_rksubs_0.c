#include <stdlib.h>
#include <stddef.h>

double y[1024 * 1024 / sizeof(double)]; // ~1MB of data
double fY[256 * 1024 * 1024 / sizeof(double)]; // ~256MB to ensure sufficient size
double b[256]; // stage dimension, sized reasonably

size_t stage = 256;
size_t dim = 1024 * 1024 / sizeof(double);
size_t i;
size_t j;

void init_vars() {
    for (size_t idx = 0; idx < dim; idx++) {
        y[idx] = 0.0;
    }
    for (size_t idx = 0; idx < stage * dim; idx++) {
        fY[idx] = (double)(idx % 100) / 100.0;
    }
    for (size_t idx = 0; idx < stage; idx++) {
        b[idx] = (double)(idx % 50) / 50.0;
    }
    i = 0;
    j = 0;
}