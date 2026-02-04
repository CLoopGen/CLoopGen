#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize the start_color array with a pattern that will make the loop run long enough
    // to take approximately 0.01 seconds. We'll create a large number of nested (...)
    // constructs to ensure the inner loop runs many times.

    const size_t data_size = 16 * 1024 * 1024; // 16 MB total logical data
    char *data = (char*)malloc(data_size);
    
    size_t pos = 0;
    // Fill with many '(' followed by some characters and then ')'
    while (pos < data_size - 200) {
        if (pos + 100 < data_size) {
            data[pos++] = '(';
            // Add ~98 random printable chars
            for (int i = 0; i < 98 && pos < data_size - 1; i++) {
                data[pos++] = 'a' + (pos % 26);
            }
            data[pos++] = ')';
        } else {
            break;
        }
    }
    
    // Ensure null termination before end
    if (pos < data_size) {
        data[pos] = '\0';
    }

    // Copy as much as fits into start_color, but we need more data
    // So instead, we redefine start_color via pointer aliasing in logic
    // But since start_color is fixed size, we must work within 4096 bytes
    // Therefore, we use it as a buffer that gets reused in streaming fashion?
    // However, loop only uses start_color and p — so we can make start_color
    // contain a representative chunk, and set p accordingly.

    // Reset pos for filling start_color
    pos = 0;
    int depth = 0;
    // Create deeply nested structure to increase scan time
    while (pos < 4000) {
        if (depth < 10 && pos < 3900) {
            data[pos++] = '(';
            depth++;
        } else {
            // Start closing
            if (depth > 0) {
                // Insert some filler
                for (int i = 0; i < 5 && pos < 4000; i++) {
                    data[pos++] = 'x';
                }
                data[pos++] = ')';
                depth--;
            } else {
                break;
            }
        }
    }
    while (depth > 0 && pos < 4090) {
        data[pos++] = ')';
        depth--;
    }
    data[pos++] = '-';
    data[pos] = '\0';

    // Copy into start_color
    memcpy(start_color, data, sizeof(start_color)-1);
    start_color[sizeof(start_color)-1] = '\0';

    free(data);

    // Initialize p to point to start of start_color
    p = start_color;
}