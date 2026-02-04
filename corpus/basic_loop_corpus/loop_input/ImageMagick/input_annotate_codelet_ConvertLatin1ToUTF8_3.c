#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned char *restrict content;
int c;
unsigned char *restrict p;
unsigned char *restrict q;

static unsigned char *content_buffer;
static unsigned char *q_buffer;
static size_t input_size = 1 << 20; // 1MB data for ~0.01 sec runtime

void init_vars() {
    content_buffer = malloc(input_size);
    q_buffer = malloc(2 * input_size);

    if (!content_buffer || !q_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < input_size - 1; i++) {
        content_buffer[i] = rand() % 256;
    }
    content_buffer[input_size - 1] = '\x00';

    content = content_buffer;
    p = content;
    q = q_buffer;
}