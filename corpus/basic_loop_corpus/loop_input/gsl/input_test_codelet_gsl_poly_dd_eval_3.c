#include <stdlib.h>
#include <time.h>

double dd[1 << 20];
double xa[1 << 20];
size_t size = 1 << 20;
double x = 1.5;
size_t i;
double y = 0.0;

void init_vars() {
    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < size; ++idx) {
        dd[idx] = ((double)rand()) / RAND_MAX;
        xa[idx] = ((double)rand()) / RAND_MAX;
    }
    y = 0.0;
    x = 1.5;
}