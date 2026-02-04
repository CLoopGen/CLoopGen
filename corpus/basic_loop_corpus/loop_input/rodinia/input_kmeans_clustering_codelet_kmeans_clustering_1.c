#include <stdlib.h>
#include <stdint.h>

int npoints;
int i;
int *initial;

void init_vars() {
    npoints = 64 * 1024 * 1024 / sizeof(int);  // ~256 MB of data for int array
    initial = (int*)calloc(npoints, sizeof(int));
    if (!initial) {
        exit(1);
    }
}