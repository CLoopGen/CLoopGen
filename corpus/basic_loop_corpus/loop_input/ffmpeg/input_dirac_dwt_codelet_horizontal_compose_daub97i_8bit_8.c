#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w2 = 8192;
int x = 0;

static int16_t *b_ptr = NULL;
static int16_t *temp_ptr = NULL;

int16_t *b = NULL;
int16_t *temp = NULL;

void init_vars() {
    const size_t data_size = 256 * 1024 * sizeof(int16_t);
    const size_t num_elements = data_size / sizeof(int16_t);

    w2 = (int)(num_elements / 4);
    if (w2 < 2) w2 = 2;

    b_ptr = (int16_t *)aligned_alloc(32, data_size);
    temp_ptr = (int16_t *)aligned_alloc(32, data_size);

    b = b_ptr;
    temp = temp_ptr;

    for (size_t i = 0; i < num_elements; i++) {
        b[i] = (int16_t)(i % 32768);
        temp[i] = 0;
    }
}