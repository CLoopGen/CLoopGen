#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB for ~0.01 sec runtime

char start_color[4096];
char *p;

static char data_buffer[DATA_SIZE];

void init_vars() {
    // Initialize start_color as a circular buffer of patterns to control traversal
    memset(start_color, 0, sizeof(start_color));
    
    // Create complex nested pattern: "abc(def)gh-"
    const char *pattern = "abc(def)gh";
    const int pat_len = strlen(pattern);
    int pos = 0;
    
    // Fill start_color with repeating pattern, ensuring '-' appears at the end
    while (pos < (int)(sizeof(start_color) - pat_len - 2)) {
        memcpy(&start_color[pos], pattern, pat_len);
        pos += pat_len;
    }
    start_color[pos] = '-'; // termination condition
    start_color[pos+1] = '\0';

    // Initialize p to start of start_color
    p = start_color;

    // Warm up data buffer to ensure it's allocated in physical memory
    for (size_t i = 0; i < sizeof(data_buffer); i += 4096) {
        data_buffer[i] = 'x';
    }
}