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
static size_t data_size;

void init_vars() {
    data_size = 64 * 1024 * 1024; // 64 MB of data
    lres_data = aligned_alloc(sizeof(unsigned long), data_size);
    first_key_data = aligned_alloc(sizeof(unsigned long), data_size);

    if (!lres_data || !first_key_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size / sizeof(unsigned long); idx++) {
        lres_data[idx] = 0xFFFFFFFFUL;
        first_key_data[idx] = 0xAAAAAAAAUL;
    }

    lres = lres_data;
    first_key = first_key_data;
    processed = data_size;
}