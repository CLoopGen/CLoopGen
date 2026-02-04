#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *big;
char *little;
char *s;
char *x;
char *littleend;

static char *big_buffer;
static char *little_buffer;

void init_vars() {
    size_t big_size = 16 * 1024 * 1024;        // 16 MB
    size_t little_size = 8 * 1024 * 1024;      // 8 MB

    // Allocate buffers
    big_buffer = (char *)malloc(big_size);
    little_buffer = (char *)malloc(little_size);

    if (!big_buffer || !little_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize big_buffer with predictable pattern
    memset(big_buffer, 'A', big_size);

    // Initialize little_buffer: first part matches big_buffer starting at offset 2, then a mismatch
    size_t match_size = little_size - 1;
    memset(little_buffer, 'A', match_size);
    little_buffer[match_size] = 'B';  // Ensure a mismatch at the end

    // Set pointers
    big = big_buffer;
    little = little_buffer;
    littleend = little_buffer + little_size;
}

// Constructor to initialize variables before main
__attribute__((constructor))
static void constructor_init() {
    init_vars();
}

// Destructor to free memory
__attribute__((destructor))
static void destructor_free() {
    free(big_buffer);
    free(little_buffer);
}