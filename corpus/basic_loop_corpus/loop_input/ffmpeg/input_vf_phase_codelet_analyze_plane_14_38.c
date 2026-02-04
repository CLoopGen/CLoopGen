#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w;
int64_t bdif;
int64_t tdif;
int64_t pdif;
int t;
uint16_t *rend;

static uint16_t *nptr_buffer;
static uint16_t *optr_buffer;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~128 MB of total data (two arrays)
    const size_t num_elements = data_size / sizeof(uint16_t) / 2;
    
    w = num_elements - 3; // Ensure we can access [ns], [ns<<1], and [-ns] safely with ns=1

    nptr_buffer = aligned_alloc(32, (num_elements + 10) * sizeof(uint16_t));
    optr_buffer = aligned_alloc(32, (num_elements + 10) * sizeof(uint16_t));

    for (size_t i = 0; i < num_elements + 5; i++) {
        nptr_buffer[i] = rand() % 256;
        optr_buffer[i] = rand() % 256;
    }

    nptr = nptr_buffer + 2;
    optr = optr_buffer + 2;

    bdif = 0;
    tdif = 0;
    pdif = 0;
    t = 0;
    rend = NULL;
}