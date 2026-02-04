#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w;
int64_t tdif;
int64_t pdif;
int t;
uint16_t *rend;

static uint16_t *nptr_buffer;
static uint16_t *optr_buffer;
static size_t total_data_size = 64 * 1024 * 1024; // ~64MB for sufficient runtime

void init_vars() {
    size_t num_elements = total_data_size / sizeof(uint16_t);
    w = num_elements - (abs(ns) << 1) - 1; // Ensure index (ns)<<1 and -ns are within bounds
    if (w <= 0) {
        w = 1;
    }

    nptr_buffer = aligned_alloc(32, num_elements * sizeof(uint16_t));
    optr_buffer = aligned_alloc(32, num_elements * sizeof(uint16_t));

    if (!nptr_buffer || !optr_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < num_elements; i++) {
        nptr_buffer[i] = rand() & 0xFFFF;
        optr_buffer[i] = rand() & 0xFFFF;
    }

    nptr = nptr_buffer;
    optr = optr_buffer;

    tdif = 0;
    pdif = 0;
    t = 0;
    rend = nptr + w;
}