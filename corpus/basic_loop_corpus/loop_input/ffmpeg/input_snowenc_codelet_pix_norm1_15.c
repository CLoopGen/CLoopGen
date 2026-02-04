#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *pix;
int line_size;
int w;
int s;
int i;
int j;
uint32_t *sq;

static uint8_t *pix_buffer;
static uint32_t *sq_buffer;

void init_vars() {
    w = 1024;
    line_size = w;
    s = 0;
    i = 0;
    j = 0;

    size_t pix_size = (size_t)w * w + line_size;
    size_t sq_size = 256;

    pix_buffer = (uint8_t*)calloc(pix_size, sizeof(uint8_t));
    sq_buffer = (uint32_t*)calloc(sq_size, sizeof(uint32_t));

    if (!pix_buffer || !sq_buffer) {
        free(pix_buffer);
        free(sq_buffer);
        exit(1);
    }

    for (size_t idx = 0; idx < sq_size; idx++) {
        sq_buffer[idx] = (uint32_t)(idx * idx);
    }

    for (size_t idx = 0; idx < pix_size; idx++) {
        pix_buffer[idx] = rand() & 0xFF;
    }

    pix = pix_buffer;
    sq = sq_buffer;
}