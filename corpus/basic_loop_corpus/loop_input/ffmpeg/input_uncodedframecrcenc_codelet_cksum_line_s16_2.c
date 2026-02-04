#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

unsigned int size;
int16_t *p;
unsigned int a;
unsigned int b;

static int16_t *data_buffer;

void init_vars() {
    const size_t data_size_bytes = 64 * 1024 * 1024; // ~64MB of data
    const unsigned int num_elements = data_size_bytes / sizeof(int16_t);

    data_buffer = (int16_t*)calloc(num_elements, sizeof(int16_t));
    if (!data_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (unsigned int i = 0; i < num_elements; i++) {
        data_buffer[i] = rand() % 65536 - 32768;
    }

    size = num_elements;
    p = data_buffer;
    a = 1;
    b = 0;
}