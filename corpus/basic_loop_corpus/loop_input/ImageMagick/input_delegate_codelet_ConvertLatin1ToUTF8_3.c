#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

unsigned char *restrict content;
int c;
unsigned char *restrict p;
unsigned char *restrict q;

static unsigned char *content_buffer;
static unsigned char *q_buffer;
static size_t input_size = 1 << 20; // 1MB
static size_t output_capacity;

void init_vars() {
    input_size = 1 << 20;
    output_capacity = 2 * input_size;

    content_buffer = aligned_alloc(64, input_size);
    q_buffer = aligned_alloc(64, output_capacity);

    if (!content_buffer || !q_buffer) {
        free(content_buffer);
        free(q_buffer);
        exit(1);
    }

    for (size_t i = 0; i < input_size - 1; i++) {
        content_buffer[i] = rand() % 256;
    }
    content_buffer[input_size - 1] = '\x00';

    content = content_buffer;
    p = content;
    q = q_buffer;
    c = 0;
}