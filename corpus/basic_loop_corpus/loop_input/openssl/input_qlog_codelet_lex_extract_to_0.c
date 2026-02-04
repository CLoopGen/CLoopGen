#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

char c;
char *p;
char *term_end;
char *s;

static char *data_buffer;
static size_t buffer_size = 512 * 1024; // 512 KB

void init_vars() {
    // Allocate buffer
    data_buffer = (char*)malloc(buffer_size);
    if (!data_buffer) {
        data_buffer = NULL;
        p = &c;
        term_end = &c;
        c = 0;
        return;
    }

    // Initialize the buffer with non-matching characters
    memset(data_buffer, 'x', buffer_size - 1);
    
    // Place the target character near the end to ensure loop runs long enough
    c = 'z';
    data_buffer[buffer_size - 2] = c; // So loop stops here
    
    // Set pointer boundaries
    p = data_buffer;
    term_end = data_buffer + buffer_size - 1; // Exclude last position to prevent accessing beyond buffer
}

// Ensure variables are properly initialized before use
__attribute__((constructor))
static void initialize() {
    init_vars();
}

__attribute__((destructor))
static void cleanup() {
    if (data_buffer) {
        free(data_buffer);
        data_buffer = NULL;
    }
}