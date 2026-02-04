#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *restrict content;
int c;
unsigned char *restrict p;
unsigned char *restrict q;

#define DATA_SIZE (128 << 20) // 128 MB

static unsigned char *content_buffer;
static unsigned char *q_buffer;
static size_t q_buffer_size;

void init_vars() {
    // Allocate input buffer with 128MB + 1 for null terminator
    content_buffer = (unsigned char*)malloc(DATA_SIZE + 1);
    if (!content_buffer) {
        fprintf(stderr, "Failed to allocate content_buffer\n");
        exit(1);
    }

    // Fill with pseudo-random data but ensure a null terminator at the end
    for (size_t i = 0; i < DATA_SIZE; ++i) {
        content_buffer[i] = rand() & 0xFF;
    }
    content_buffer[DATA_SIZE] = '\x00'; // Null terminate

    // Set content to point to the beginning of the allocated buffer
    content = content_buffer;

    // Allocate output buffer: worst case is 2 bytes per input byte (if all high-bit set)
    q_buffer_size = 2 * DATA_SIZE + 1;
    q_buffer = (unsigned char*)malloc(q_buffer_size);
    if (!q_buffer) {
        fprintf(stderr, "Failed to allocate q_buffer\n");
        exit(1);
    }

    // Initialize q to start of output buffer
    q = q_buffer;

    // Initialize p to start of content
    p = content;

    // Initialize scalar variable c
    c = 0;
}