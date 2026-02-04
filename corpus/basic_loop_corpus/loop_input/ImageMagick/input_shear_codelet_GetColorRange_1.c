#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB

char start_color[DATA_SIZE];
char *p;

void init_vars() {
    // Initialize the buffer with a pattern that includes parentheses and ends with null
    size_t pos = 0;
    const char pattern[] = "abc(defg)hij-klm";
    const size_t pattern_len = strlen(pattern);
    
    while (pos < DATA_SIZE - 1) {
        size_t remaining = DATA_SIZE - pos - 1;
        size_t copy_size = (remaining < pattern_len) ? remaining : pattern_len;
        memcpy(start_color + pos, pattern, copy_size);
        pos += copy_size;
    }
    
    // Ensure the last character is null terminator
    start_color[DATA_SIZE - 1] = '\0';
    
    // Reset p to point to start of buffer
    p = start_color;
}