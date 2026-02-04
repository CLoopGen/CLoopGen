#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with data to ensure loop runs for desired time
    // We'll create a pattern that causes the loop to iterate sufficiently
    // The loop processes characters until '-' or '\0', skipping content inside '(' and ')'
    
    size_t total_size = 1 << 20; // ~1MB, adjust if needed for timing
    char *data = (char *)malloc(total_size);
    if (!data) exit(1);

    size_t pos = 0;
    // Create repeating pattern: "abc(def)" multiple times, then end with '-'
    const char *pattern = "abc(def)";
    size_t pattern_len = 7; // without null
    size_t repeat_count = total_size / (pattern_len + 1); // allow space

    for (size_t i = 0; i < repeat_count && pos + pattern_len + 1 < total_size - 4096; i++) {
        for (size_t j = 0; j < pattern_len; j++) {
            data[pos++] = pattern[j];
        }
        data[pos++] = ' ';
    }
    data[pos++] = '-';
    data[pos] = '\0';

    // Copy segment into start_color (we only have 4096 bytes)
    size_t copy_size = (pos > 4096 - 1) ? 4096 - 1 : pos;
    for (size_t i = 0; i < copy_size; i++) {
        start_color[i] = data[i];
    }
    start_color[copy_size] = '\0';

    free(data);

    // Initialize p to start of start_color
    p = start_color;
}