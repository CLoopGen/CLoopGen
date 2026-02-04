#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *restrict content;
int c;
unsigned char *restrict p;
unsigned char *restrict q;

#define INPUT_SIZE (16 << 20) // 16 MB input size for ~0.01 sec runtime
#define OUTPUT_BUFFER_SIZE (INPUT_SIZE * 2) // Worst case: each byte expands to 2 bytes

static unsigned char content_data[INPUT_SIZE];
static unsigned char output_buffer[OUTPUT_BUFFER_SIZE];

void init_vars() {
    // Initialize content with random-like data including high-bit set bytes
    for (size_t i = 0; i < INPUT_SIZE - 1; i++) {
        // Mix of ASCII and bytes with high bit set to trigger both branches
        content_data[i] = (unsigned char)((i * 97) % 256); // Deterministic pattern
    }
    content_data[INPUT_SIZE - 1] = '\x00'; // Null terminator as loop condition

    // Initialize pointers
    content = content_data;
    p = content;
    q = output_buffer;
    c = 0;
}