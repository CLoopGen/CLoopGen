#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[262144]; // 256KB buffer
char *p;

void init_vars() {
    // Initialize with a large string containing nested patterns to ensure meaningful loop execution
    size_t size = sizeof(start_color) - 1; // Leave space for null terminator
    char *data = start_color;
    
    // Fill the buffer with repeating patterns of text and parentheses
    size_t pos = 0;
    const char chunk[] = "abc(defg)hij-klm";
    const size_t chunk_len = sizeof(chunk) - 1;
    const size_t segment = chunk_len * 10; // Repeat pattern every 10 instances

    while (pos + segment + 1 < size) {
        memcpy(data + pos, chunk, chunk_len);
        pos += chunk_len;
    }

    // Insert '-' near the end to stop the outer loop naturally
    data[size - 1] = '-';
    data[size] = '\0';
}