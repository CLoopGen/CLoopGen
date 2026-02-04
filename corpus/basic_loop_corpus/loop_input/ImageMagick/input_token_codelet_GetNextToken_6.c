#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char *restrict start;
size_t extent;
char *restrict token;
char *restrict q;
char *restrict p;
ssize_t i;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01s runtime

static char *buffer;
static char *token_buffer;

void init_vars() {
    // Allocate input buffer
    buffer = aligned_alloc(64, DATA_SIZE);
    if (!buffer) exit(1);

    // Fill with printable ASCII, insert a comma near the end to terminate early
    memset(buffer, 'x', DATA_SIZE);
    buffer[DATA_SIZE - 1000] = ',';

    // Allocate token buffer
    token_buffer = aligned_alloc(64, DATA_SIZE);
    if (!token_buffer) exit(1);
    memset(token_buffer, 0, DATA_SIZE);

    // Initialize variables
    start = buffer;
    extent = DATA_SIZE;
    token = token_buffer;
    p = start;
    q = start + extent;
    i = 0;
}