#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

typedef float real_t;

real_t *arr;
int length;
real_t value;
int stride;

void init_vars() {
    length = 64 * 1024 * 1024 / sizeof(real_t);  // ~256 MB of data to ensure ~0.01s runtime
    stride = 1;
    value = 3.14159f;

    arr = (real_t*)aligned_alloc(32, length * sizeof(real_t));
    if (!arr) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    memset(arr, 0, length * sizeof(real_t));
}