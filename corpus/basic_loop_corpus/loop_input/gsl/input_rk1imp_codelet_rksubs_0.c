#include <stdlib.h>
#include <stddef.h>

double y[65536];
double fY[1048576];
double b[16];
size_t stage = 16;
size_t dim = 65536;
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
        b[idx] = (double)(idx + 1);
    }
}