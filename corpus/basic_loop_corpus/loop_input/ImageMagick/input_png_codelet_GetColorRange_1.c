#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize the start_color array with a pattern that ensures safe traversal
    // and approximately matches the expected runtime behavior.
    // We'll create a large buffer (1MB) of data that contains nested patterns
    // to simulate realistic traversal without going out of bounds.

    const size_t DATA_SIZE = 1024 * 1024; // 1MB for ~0.01 sec runtime estimate
    static char* large_buffer = NULL;
    
    if (large_buffer == NULL) {
        large_buffer = (char*)malloc(DATA_SIZE);
        if (!large_buffer) exit(1);
    }

    // Fill with mostly alphanumeric and common delimiters
    size_t idx = 0;
    while (idx < DATA_SIZE - 50) {
        // Randomly insert either plain text or parenthesized group
        if ((rand() % 5) == 0) {
            large_buffer[idx++] = '(';
            int group_len = 3 + (rand() % 15);
            for (int i = 0; i < group_len && idx < DATA_SIZE - 10; i++) {
                large_buffer[idx++] = 'a' + (rand() % 26);
            }
            large_buffer[idx++] = ')';
        } else {
            large_buffer[idx++] = 'a' + (rand() % 26);
        }
        
        // Occasionally insert '-' to allow loop termination possibility
        if ((rand() % 100) == 0 && idx < DATA_SIZE - 50) {
            large_buffer[idx++] = '-';
            break;
        }
    }

    // Ensure null termination before buffer end
    if (idx >= DATA_SIZE) idx = DATA_SIZE - 1;
    large_buffer[idx] = '\0';

    // Copy into start_color in chunks, but ensure we don't overflow it
    size_t copy_size = (sizeof(start_color) - 1 < idx) ? sizeof(start_color) - 1 : idx;
    memcpy(start_color, large_buffer, copy_size);
    start_color[copy_size] = '\0';

    // Ensure p is initialized properly by other code via assignment in loop
    // Do not set p here as it's controlled during loop execution
}