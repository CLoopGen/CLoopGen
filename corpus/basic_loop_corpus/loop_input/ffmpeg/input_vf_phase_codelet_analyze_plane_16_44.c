#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w = 65536;
int64_t bdif;
int64_t tdif;
int t;
uint16_t *rend;

static uint16_t *nptr_buffer;
static uint16_t *optr_buffer;

void init_vars() {
    size_t data_size = 131072; // 256 KB of data (each element is 2 bytes)
    nptr_buffer = aligned_alloc(64, data_size * sizeof(uint16_t));
    optr_buffer = aligned_alloc(64, data_size * sizeof(uint16_t));

    if (!nptr_buffer || !optr_buffer) {
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < data_size; i++) {
        nptr_buffer[i] = (uint16_t)(i & 0xFFFF);
        optr_buffer[i] = (uint16_t)((i + 100) & 0xFFFF);
    }

    nptr = nptr_buffer;
    optr = optr_buffer;
    bdif = 0;
    tdif = 0;
    t = 0;
    rend = nptr + w;
}