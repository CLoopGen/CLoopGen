#include <stdio.h>
#include <inttypes.h>

typedef int int32;
typedef int32 tsize_t;
typedef unsigned short uint16;

tsize_t stride;
uint16 *wp;
int i;

static uint16 *wp_storage;
static tsize_t total_size;

void init_vars() {
    total_size = 64 * 1024 * 1024 / sizeof(uint16); // ~64 MB of data
    wp_storage = (uint16*)__builtin_malloc(total_size * sizeof(uint16));
    stride = 10000; // Ensures loop runs with valid bounds and non-zero decrement
    wp = wp_storage + 4; // Offset so that wp[stride] and wp[0] are in bounds during loop

    for (tsize_t idx = 0; idx < total_size; idx++) {
        wp_storage[idx] = (uint16)(idx & 0xFFFF);
    }
}