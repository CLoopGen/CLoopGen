#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

char *source;
size_t bytes;
long value;
int i;

static char *internal_source;
static size_t internal_bytes = 1 << 20; // 1MB data size for ~0.01 sec runtime estimate

void init_vars() {
    internal_source = (char *)malloc(internal_bytes);
    if (!internal_source) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    // Initialize source data with predictable pattern
    for (size_t idx = 0; idx < internal_bytes; idx++) {
        internal_source[idx] = (char)(idx & 255);
    }
    
    // Setup external variables
    source = internal_source;
    bytes = internal_bytes;
    value = 0;
    i = (int)(bytes - 1); // Ensure valid index range: i from (bytes-1) down to 0
}

// Cleanup function to avoid memory leaks (if needed elsewhere)
void cleanup_vars() {
    free(internal_source);
    internal_source = NULL;
}