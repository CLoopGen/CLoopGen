#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coeffs;
int x;
int y;
int size;

static int16_t *coeffs_storage;
static ptrdiff_t coeffs_stride;

void init_vars() {
    size = 8192;
    coeffs_stride = size * sizeof(int16_t);
    coeffs_storage = aligned_alloc(32, (size_t)size * (size_t)size * sizeof(int16_t));
    coeffs = coeffs_storage;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            coeffs_storage[i * size + j] = (int16_t)(j + 1);
        }
    }
}