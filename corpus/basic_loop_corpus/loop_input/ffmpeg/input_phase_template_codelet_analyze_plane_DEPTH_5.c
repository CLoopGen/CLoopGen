#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int ns = 1;
int os = 1;
uint16_t *nptr = NULL;
uint16_t *optr = NULL;
int w = 0;
int64_t bdif = 0;
int64_t tdif = 0;
int t = 0;
uint16_t *rend = NULL;

static uint16_t *nptr_base = NULL;
static uint16_t *optr_base = NULL;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data for each array
    const size_t num_elements = data_size / sizeof(uint16_t);

    w = num_elements - 4; // Ensure safe access within bounds: need up to [ns<<1], [-os], etc.

    if (w <= 0) {
        fprintf(stderr, "Data size too small\n");
        exit(1);
    }

    nptr_base = aligned_alloc(32, (num_elements + 10) * sizeof(uint16_t));
    optr_base = aligned_alloc(32, (num_elements + 10) * sizeof(uint16_t));

    if (!nptr_base || !optr_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < num_elements + 10; i++) {
        nptr_base[i] = rand() % 100;
        optr_base[i] = rand() % 100;
    }

    nptr = nptr_base + 2;
    optr = optr_base + 2;

    bdif = 0;
    tdif = 0;
}