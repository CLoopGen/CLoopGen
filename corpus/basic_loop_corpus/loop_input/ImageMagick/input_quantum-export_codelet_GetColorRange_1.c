#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize the start_color array with data that ensures the loop runs for a significant time
    // We'll create a large buffer with nested patterns to simulate realistic traversal
    const size_t total_size = 128 * 1024 * 1024; // 128 MB of data
    char *data = (char*)malloc(total_size);
    
    size_t pos = 0;
    // Fill with repeating patterns: "abc(def)gh-ijkl(mno)pqr-stu(vwx)yz..."
    while (pos < total_size - 10) {
        if ((pos / 50) % 3 == 0) {
            data[pos++] = '-';
        } else {
            data[pos++] = 'a' + ((pos / 10) % 26);
            if ((pos & 7) == 0) {
                data[pos++] = '(';
                data[pos++] = 'x';
                data[pos++] = 'y';
                data[pos++] = 'z';
                data[pos++] = ')';
            }
        }
    }
    // Ensure null termination before end
    data[total_size - 1] = '\0';

    // Set up start_color as a window into our large data block
    // Use first 4096 bytes of patterned data
    for (int i = 0; i < 4096 && i < (int)total_size; i++) {
        start_color[i] = data[i];
    }

    // Make sure there's no premature null in start_color
    for (int i = 0; i < 4095; i++) {
        if (start_color[i] == '\0') {
            start_color[i] = 'A';
        }
    }
    start_color[4095] = '\0'; // Ensure null at last byte

    // Initialize p to point to start of start_color
    p = start_color;

    free(data);
}