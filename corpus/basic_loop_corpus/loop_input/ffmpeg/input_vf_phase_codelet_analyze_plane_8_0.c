#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int ns;
int os;
uint8_t *nptr;
uint8_t *optr;
int w;
int tdif;
int pdif;
int t;
uint8_t *rend;

static uint8_t *n_buffer;
static uint8_t *o_buffer;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

    n_buffer = (uint8_t*)aligned_alloc(32, data_size);
    o_buffer = (uint8_t*)aligned_alloc(32, data_size);

    if (!n_buffer || !o_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        n_buffer[i] = rand() & 0xFF;
        o_buffer[i] = rand() & 0xFF;
    }

    ns = 1;
    os = 1;
    w = data_size - (ns << 1) - 1;
    if (w <= 0) {
        w = 1;
    }

    nptr = n_buffer + (ns << 1);
    optr = o_buffer + (os << 1);

    tdif = 0;
    pdif = 0;
    t = 0;
    rend = nptr + w;
}