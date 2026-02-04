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

static uint16_t *nptr_data;
static uint16_t *optr_data;

void init_vars() {
    const size_t data_size = 262144; // ~512KB of data (2 arrays × 262144 × 2 bytes)

    nptr_data = aligned_alloc(64, data_size * sizeof(uint16_t));
    optr_data = aligned_alloc(64, data_size * sizeof(uint16_t));

    if (!nptr_data || !optr_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        nptr_data[i] = rand() % 1000;
        optr_data[i] = rand() % 1000;
    }

    nptr = nptr_data;
    optr = optr_data;

    bdif = 0;
    tdif = 0;
}