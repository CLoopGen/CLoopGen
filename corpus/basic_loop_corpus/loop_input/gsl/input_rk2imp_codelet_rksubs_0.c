#include <stdlib.h>
#include <stddef.h>

double y[131072];           // dim up to 131072 to target ~0.01s runtime
double fY[524288];           // stage * dim, assuming stage <= 4
double b[4];                 // stage is at most 4 based on typical use
size_t stage = 4;
size_t dim = 131072;
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
        b[idx] = (double)(idx + 1) / 10.0;
    }
    i = 0;
    j = 0;
}