#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long i;
unsigned long *lres;
size_t processed;
unsigned long *first_key;

static unsigned long *lres_base;
static unsigned long *first_key_base;
static size_t data_size;

void init_vars() {
    data_size = 64 * 1024 * 1024; // 64 MB of data
    processed = data_size / sizeof(unsigned long);
    lres_base = aligned_alloc(32, data_size);
    first_key_base = aligned_alloc(32, data_size);

    if (!lres_base || !first_key_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < processed; ++idx) {
        lres_base[idx] = rand();
        first_key_base[idx] = rand();
    }

    lres = lres_base;
    first_key = first_key_base;
}