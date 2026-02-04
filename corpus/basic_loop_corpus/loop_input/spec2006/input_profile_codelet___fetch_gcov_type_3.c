#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <sys/time.h>

typedef long gcov_type;

char *source;
size_t bytes;
gcov_type value;
int i;

void init_vars() {
    // Set data size to ~64MB to ensure loop runs for significant time (~0.01 sec on modern CPU)
    bytes = 64 * 1024 * 1024;
    
    // Allocate source buffer
    source = (char *)malloc(bytes);
    if (!source) {
        exit(1);
    }
    
    // Initialize source with predictable pattern to allow compiler to avoid assumptions
    for (size_t idx = 0; idx < bytes; idx++) {
        source[idx] = (char)(idx & 0xFF);
    }
    
    // Initialize value to a non-zero starting point
    value = 123456789L;
    
    // Set loop index i to last valid index of source array
    i = (int)(bytes - 1);
}