#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
int start_x;
uint8_t *bufp;

static uint8_t *internal_buf;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64 MB for ~0.01 sec runtime estimate
    internal_buf = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    if (!internal_buf) exit(1);

    bufp = internal_buf;
    start_x = data_size - 1; // ensures bufp[start_x] is valid and within bounds
}