#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *in;
uint8_t *threshold;
uint8_t *min;
uint8_t *max;
uint8_t *out;
ptrdiff_t ilinesize;
ptrdiff_t tlinesize;
ptrdiff_t flinesize;
ptrdiff_t slinesize;
ptrdiff_t olinesize;
int w;
int h;
int x;
int y;

static uint8_t *in_buffer;
static uint8_t *threshold_buffer;
static uint8_t *min_buffer;
static uint8_t *max_buffer;
static uint8_t *out_buffer;

void init_vars() {
    w = 1024;
    h = 512;

    ilinesize = w;
    tlinesize = w;
    flinesize = w;
    slinesize = w;
    olinesize = w;

    size_t total_size = (size_t)w * h;

    in_buffer = aligned_alloc(32, total_size);
    threshold_buffer = aligned_alloc(32, total_size);
    min_buffer = aligned_alloc(32, total_size);
    max_buffer = aligned_alloc(32, total_size);
    out_buffer = aligned_alloc(32, total_size);

    in = in_buffer;
    threshold = threshold_buffer;
    min = min_buffer;
    max = max_buffer;
    out = out_buffer;

    for (size_t i = 0; i < total_size; i++) {
        in_buffer[i] = rand() % 256;
        threshold_buffer[i] = 128;
        min_buffer[i] = 0;
        max_buffer[i] = 255;
    }
}