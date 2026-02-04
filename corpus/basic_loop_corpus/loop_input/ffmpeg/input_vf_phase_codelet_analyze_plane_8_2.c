#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint8_t *nptr = NULL;
uint8_t *optr = NULL;
int w = 0;
int bdif = 0;
int pdif = 0;
int t = 0;
uint8_t *rend = NULL;

static uint8_t *nbuf = NULL;
static uint8_t *obuf = NULL;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64 MB for ~0.01 sec runtime estimate
    w = data_size;

    nbuf = (uint8_t*)aligned_alloc(32, data_size + 4 * sizeof(uint8_t));
    obuf = (uint8_t*)aligned_alloc(32, data_size + 4 * sizeof(uint8_t));

    if (!nbuf || !obuf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        nbuf[i] = rand() & 0xFF;
        obuf[i] = rand() & 0xFF;
    }

    // Initialize boundary regions to prevent out-of-bounds access
    for (int i = 0; i < 2; i++) {
        nbuf[data_size + i] = rand() & 0xFF;
        nbuf[-1 - i] = rand() & 0xFF;
        obuf[data_size + i] = rand() & 0xFF;
        obuf[-1 - i] = rand() & 0xFF;
    }

    nptr = nbuf + 1;   // leave room for negative index: nptr[-ns]
    optr = obuf + 1;   // same for optr
    rend = nptr + w - 2; // ensure nptr[ns], nptr[ns<<1], nptr[-ns] are valid
}