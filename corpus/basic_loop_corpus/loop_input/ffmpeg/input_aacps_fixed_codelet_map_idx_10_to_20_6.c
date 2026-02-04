#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int8_t *par_mapped;
int8_t *par;
int b;

static int8_t *par_mapped_buf;
static int8_t *par_buf;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024;
    par_buf = (int8_t*)aligned_alloc(32, data_size);
    par_mapped_buf = (int8_t*)aligned_alloc(32, 2 * data_size);

    if (!par_buf || !par_mapped_buf) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        par_buf[i] = (int8_t)(i & 0xFF);
    }

    par = par_buf;
    par_mapped = par_mapped_buf;
    b = (int)(data_size - 1);
}