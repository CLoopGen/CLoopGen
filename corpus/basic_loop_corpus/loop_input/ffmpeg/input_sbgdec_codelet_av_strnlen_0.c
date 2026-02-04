#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

static char *buffer;
static size_t buffer_size;

void init_vars() {
    buffer_size = 64 << 20; // 64 MB
    buffer = (char*)calloc(buffer_size, sizeof(char));
    if (!buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
    
    // Fill with non-zero bytes except the last one
    for (size_t j = 0; j < buffer_size - 1; j++) {
        buffer[j] = 'a';
    }
    buffer[buffer_size - 1] = '\0';
    
    s = buffer;
    len = buffer_size;
    i = 0;
}

// Forward declaration of loop function
void loop();