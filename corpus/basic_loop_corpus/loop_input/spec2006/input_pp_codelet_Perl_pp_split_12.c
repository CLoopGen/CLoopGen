#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

char *s;
char *strend;
char *m;
char c;

static char *buffer;
static size_t buffer_size = 1 << 20; // 1MB

void init_vars() {
    buffer = (char*)malloc(buffer_size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize buffer with non-null data
    memset(buffer, 'x', buffer_size);
    
    // Place the character to be found near the end to ensure loop runs long enough
    c = 'y';
    size_t target_pos = buffer_size - 1000;
    buffer[target_pos] = c;

    // Set pointers
    s = buffer;
    strend = buffer + buffer_size;
    m = NULL; // Will be initialized in loop
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}

__attribute__((destructor))
static void destructor() {
    free(buffer);
}