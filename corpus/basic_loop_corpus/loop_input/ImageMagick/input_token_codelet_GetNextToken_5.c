#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char *restrict start;
size_t extent;
char *restrict token;
char *restrict p;
ssize_t i;
char escape;

static char *buffer;
static char *token_buffer;

void init_vars() {
    extent = 64 * 1024 * 1024;  // 64 MB to target ~0.01 sec runtime on modern CPU

    // Allocate input buffer with space for null terminator
    buffer = (char*)malloc(extent + 1);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize most bytes to normal characters
    memset(buffer, 'a', extent);
    
    // Place escape sequences near the middle to ensure loop processes substantial data
    size_t mid = extent / 2;
    escape = '"';  // Choose quote as escape char
    
    // Insert escaped characters: \\ and \"
    buffer[mid] = '\\';
    buffer[mid+1] = '\\';
    buffer[mid+2] = '"';
    buffer[mid+3] = '\\';
    buffer[mid+4] = escape;  // This will trigger the break condition
    
    // Null terminate
    buffer[extent] = '\x00';

    start = buffer;
    p = start - 1;  // Will be incremented at start of loop

    // Allocate token output buffer
    token_buffer = (char*)malloc(extent);
    if (!token_buffer) {
        fprintf(stderr, "Token buffer allocation failed\n");
        free(buffer);
        exit(1);
    }
    token = token_buffer;

    i = 0;
}

// Cleanup function to avoid memory leaks (not called here but implied usage)
void cleanup_vars() {
    free(buffer);
    free(token_buffer);
}