#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long i;
unsigned long *lres;
size_t processed;
unsigned long *first_key;

static unsigned long *lres_data;
static unsigned long *first_key_data;
static size_t total_elements;

void init_vars() {
    total_elements = (1 << 24) / sizeof(unsigned long); // ~16 MB of data
    processed = (total_elements / 4) * 4; // Ensure multiple of 4 for the loop unrolling

    lres_data = aligned_alloc(32, total_elements * sizeof(unsigned long));
    first_key_data = aligned_alloc(32, total_elements * sizeof(unsigned long));

    if (!lres_data || !first_key_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_elements; ++idx) {
        lres_data[idx] = 0xAAAAAAAAAAAAAAAAUL;
        first_key_data[idx] = 0x5555555555555555UL;
    }

    lres = lres_data;
    first_key = first_key_data;
}