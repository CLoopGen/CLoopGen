#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

unsigned int size;
int32_t *p;
unsigned int a;
unsigned int b;

static int32_t *data_buffer;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M elements, ~256MB for int32_t
    data_buffer = (int32_t *)malloc(data_size * sizeof(int32_t));
    if (!data_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    // Seed random generator for realistic input
    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < data_size; i++) {
        data_buffer[i] = (int32_t)(rand() % 10000 - 5000); // Small varied values
    }

    // Initialize loop variables
    size = (unsigned int)data_size;
    p = data_buffer;
    a = 1;
    b = 0;
}