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
static unsigned char *output_buffer;

void init_vars() {
    size_t input_size = 16777216; // 16 MB
    size_t output_capacity = input_size * 2; // Worst case: each byte expands to 2 bytes

    // Allocate memory
    content_buffer = (unsigned char*)malloc(input_size);
    output_buffer = (unsigned char*)malloc(output_capacity);
    
    if (!content_buffer || !output_buffer) {
        free(content_buffer);
        free(output_buffer);
        exit(1);
    }

    // Seed random number generator for realistic data distribution
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&input_size));

    // Initialize content with mixed ASCII and high-bit-set bytes
    for (size_t i = 0; i < input_size - 1; i++) {
        // Approximately 75% regular ASCII, 25% high-bit-set characters
        if (rand() % 100 < 75) {
            content_buffer[i] = (unsigned char)(rand() % 128);
        } else {
            content_buffer[i] = (unsigned char)(128 + (rand() % 128));
        }
    }
    
    // Ensure null terminator at end
    content_buffer[input_size - 1] = '\x00';

    // Set pointers
    content = content_buffer;
    p = content;
    q = output_buffer;
    c = 0;
}

// Cleanup function to avoid memory leaks (not called here but good practice)
void cleanup_vars() {
    free(content_buffer);
    free(output_buffer);
    content_buffer = NULL;
    output_buffer = NULL;
}