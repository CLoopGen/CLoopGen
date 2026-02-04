#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w;
int64_t tdif;
int64_t pdif;
int t;
uint16_t *rend;

static uint16_t *nptr_base;
static uint16_t *optr_base;
static size_t data_size;

void init_vars() {
    data_size = 64 * 1024 * 1024; // 64 MB of data for nptr
    nptr_base = (uint16_t*)aligned_alloc(32, data_size * sizeof(uint16_t));
    optr_base = (uint16_t*)aligned_alloc(32, data_size * sizeof(uint16_t));

    if (!nptr_base || !optr_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        nptr_base[i] = rand() % 1000;
        optr_base[i] = rand() % 1000;
    }

    nptr = nptr_base + 1; // Start from index 1 to allow access at -ns and +ns
    optr = optr_base + 1;
    w = data_size - 2;   // Ensure valid access: indices -ns, ns, 2*ns are within bounds

    tdif = 0;
    pdif = 0;
    t = 0;
    rend = NULL;
}