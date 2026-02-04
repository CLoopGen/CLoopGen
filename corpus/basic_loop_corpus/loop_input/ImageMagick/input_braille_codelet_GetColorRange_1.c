#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB

char start_color[4096];
char *p;

static char data_buffer[DATA_SIZE];

void init_vars() {
    // Initialize start_color with pattern that includes parentheses and ends with '-'
    // Ensure no buffer overflow by limiting to 4095 + 1 for null terminator
    const char *pattern = "abc(defg)hij(klmn)opq-rst";
    size_t pat_len = strlen(pattern);
    size_t i = 0;
    while (i < sizeof(start_color) - 1) {
        size_t remaining = sizeof(start_color) - 1 - i;
        size_t chunk = (remaining < pat_len) ? remaining : pat_len;
        memcpy(start_color + i, pattern, chunk);
        i += chunk;
    }
    start_color[sizeof(start_color) - 1] = '\0';

    // Initialize p to point to start of start_color
    p = start_color;

    // Warm up or initialize any other necessary state
    // (No additional initialization needed beyond above)
}