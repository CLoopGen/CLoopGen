#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef float real_t;

real_t *arr;
int length;

void init_vars() {
    length = 67108864; // Approximately 256MB of float data (67M elements * 4 bytes)
    arr = (real_t*)aligned_alloc(32, length * sizeof(real_t));
}