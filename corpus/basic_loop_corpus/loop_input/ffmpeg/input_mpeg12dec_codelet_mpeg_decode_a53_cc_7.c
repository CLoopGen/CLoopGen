#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *p;
int cc_count;
int i;
uint8_t field1;
uint8_t *cap;

static uint8_t *p_storage;
static uint8_t *cap_storage;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // 128 MB of input data
    const size_t element_size = 6;
    const size_t num_elements = data_size / element_size;

    p_storage = aligned_alloc(32, data_size);
    cap_storage = aligned_alloc(32, data_size);

    if (!p_storage || !cap_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        p_storage[idx] = rand() % 256;
    }

    p = p_storage;
    cap = cap_storage;
    cc_count = num_elements;
    field1 = 1; // Initialize to a valid value (0 or 1), here chosen as 1
    i = 0;
}