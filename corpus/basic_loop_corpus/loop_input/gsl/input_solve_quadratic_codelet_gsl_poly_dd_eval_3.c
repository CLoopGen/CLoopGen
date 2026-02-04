#include <stdlib.h>
#include <time.h>

double dd[1048576];
double xa[1048576];
size_t size = 1048576;
double x = 1.5;
size_t i;
double y;

void init_vars() {
    srand(time(NULL));
    for (size_t idx = 0; idx < size; ++idx) {
        dd[idx] = ((double)rand()) / RAND_MAX;
        xa[idx] = ((double)rand()) / RAND_MAX;
    }
    y = 1.0;
    i = size;
}