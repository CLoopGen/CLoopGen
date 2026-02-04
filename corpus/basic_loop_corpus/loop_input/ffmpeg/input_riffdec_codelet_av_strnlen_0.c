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
    size_t data_size = 64 << 20; // 64 MB to ensure ~0.01 sec runtime on modern CPUs
    internal_buffer = (char*)calloc(data_size, sizeof(char));
    if (!internal_buffer) {
        exit(EXIT_FAILURE);
    }
    
    // Fill with non-zero up to near the end to force loop to iterate through most of the buffer
    size_t fill_size = data_size - 1;
    memset(internal_buffer, 'x', fill_size);
    
    // Null terminate at the end so s[i] eventually becomes false
    internal_buffer[fill_size] = '\0';
    
    s = internal_buffer;
    len = data_size;
    i = 0;
}