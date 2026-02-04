#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char start_color[262144]; // 256KB buffer
char *p;

void init_vars() {
    // Initialize the buffer with a pattern that will make the loop run for significant time
    size_t total_size = sizeof(start_color);
    char *data = start_color;
    
    // Fill with nested parentheses and non-terminating characters to force deep scanning
    size_t pos = 0;
    while (pos < total_size - 10) {
        if (pos + 20 < total_size) {
            data[pos++] = '(';
            // Add several non-paren characters inside
            for (int j = 0; j < 15 && pos < total_size - 1; j++) {
                data[pos++] = 'a' + (j % 26);
            }
            data[pos++] = ')';
            // Add some normal scanning characters
            for (int j = 0; j < 5 && pos < total_size - 1; j++) {
                data[pos++] = 'x';
            }
        } else {
            break;
        }
    }
    
    // Ensure we don't fill the entire buffer so we can break on '-' or '\0'
    // Place a terminating condition near the end to prevent overflow
    if (pos < total_size - 1) {
        // Use '-' as terminator so loop stops naturally
        data[pos] = '-';
        pos++;
    }
    
    // Null terminate just in case
    if (pos < total_size) {
        memset(&data[pos], 'x', total_size - pos - 1);
        data[total_size - 1] = '\0';
    }
}