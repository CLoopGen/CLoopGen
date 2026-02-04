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
static size_t input_size = 1 << 20; // 1MB data for ~0.01 sec runtime estimate
static size_t output_size = 2 << 20; // Up to 2x expansion in worst-case UTF-8 encoding

void init_vars() {
    content_buffer = (unsigned char*)malloc(input_size);
    q_buffer = (unsigned char*)malloc(output_size);
    if (!content_buffer || !q_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize content with mixed high-bit and low-bit characters
    for (size_t i = 0; i < input_size - 1; i++) {
        content_buffer[i] = (unsigned char)(rand() % 256); // Includes values with and without bit 7 set
    }
    content_buffer[input_size - 1] = '\x00'; // Null terminator

    content = content_buffer;
    p = content;
    q = q_buffer;
    c = 0;
}