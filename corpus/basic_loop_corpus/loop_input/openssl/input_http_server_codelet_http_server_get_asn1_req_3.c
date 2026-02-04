#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *url;
char *end;

static char data_buffer[1024 * 128]; // 128KB buffer

void init_vars() {
    // Initialize the data buffer with printable characters and a single space near the end
    size_t i;
    size_t break_point = 98304; // Around 75% through 128KB
    
    for (i = 0; i < sizeof(data_buffer) - 1; i++) {
        if (i == break_point) {
            data_buffer[i] = ' ';
        } else {
            // Use a repeating pattern of alphanumeric chars
            data_buffer[i] = 'a' + (i % 26);
        }
    }
    data_buffer[sizeof(data_buffer) - 1] = '\0';
    
    // Initialize url to point to the buffer
    url = data_buffer;
    
    // Initialize end to avoid undefined behavior
    end = url;
}