#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *internal_buffer;

void init_vars() {
    len = 128 * 1024 * 1024; // 128 MB to target ~0.01 sec on modern CPU
    internal_buffer = (char *)malloc(len);
    if (!internal_buffer) {
        exit(1);
    }
    
    // Fill with non-zero bytes to simulate string data
    memset(internal_buffer, 'x', len - 1);
    // Null-terminate near the end so loop runs long but terminates
    internal_buffer[len - 1] = '\0';
    
    s = internal_buffer;
    i = 0;
}