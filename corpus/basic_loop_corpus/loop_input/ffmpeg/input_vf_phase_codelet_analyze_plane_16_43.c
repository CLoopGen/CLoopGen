#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w = 1 << 20; // 1MB of uint16_t data: 524,288 elements
int64_t bdif;
int64_t pdif;
int t;
uint16_t *rend;

static uint16_t *narr;
static uint16_t *oarr;

void init_vars() {
    size_t total_size = w + (w >> 1); // Ensure enough space for ns and os indexing with margin
    narr = calloc(total_size, sizeof(uint16_t));
    oarr = calloc(total_size, sizeof(uint16_t));

    if (!narr || !oarr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        narr[i] = rand() & 0xFFFF;
        oarr[i] = rand() & 0xFFFF;
    }

    nptr = narr;
    optr = oarr;
    rend = nptr + w;
}