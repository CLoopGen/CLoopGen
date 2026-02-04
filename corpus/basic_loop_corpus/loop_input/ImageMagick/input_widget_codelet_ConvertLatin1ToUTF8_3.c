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

#define INPUT_SIZE (128 * 1024 * 1024) // 128 MB for ~0.01 sec on modern CPU
#define OUTPUT_BUFFER_SIZE (INPUT_SIZE * 2)

static unsigned char input_data[INPUT_SIZE];
static unsigned char output_buffer[OUTPUT_BUFFER_SIZE];

void init_vars() {
    // Initialize input data with mixed high-bit and low-bit characters
    for (size_t i = 0; i < INPUT_SIZE - 1; i++) {
        // Use a mix of ASCII and extended ASCII to trigger both branches
        input_data[i] = (i % 131); // Values 0-130, so some have high bit set
    }
    input_data[INPUT_SIZE - 1] = '\x00'; // Null terminate

    // Allocate and initialize content to point to input_data
    content = input_data;

    // Initialize q to start of output buffer
    q = output_buffer;

    // Initialize p to start of content
    p = content;

    // Initialize c to zero
    c = 0;
}