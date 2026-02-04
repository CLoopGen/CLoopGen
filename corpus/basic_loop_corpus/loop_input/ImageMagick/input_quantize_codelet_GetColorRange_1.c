#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB for ~0.01 sec runtime

char start_color[DATA_SIZE];
char *p;

void init_vars() {
    // Initialize the start_color array with a pattern that includes parentheses and ends with '-' or '\0'
    size_t pos = 0;
    
    // Fill most of the buffer with printable characters including '(' and ')'
    while (pos < DATA_SIZE - 256) {
        if (rand() % 50 == 0) {
            start_color[pos++] = '(';
            // Add some content inside parentheses
            int len = rand() % 30 + 1;
            for (int i = 0; i < len && pos < DATA_SIZE - 2; i++) {
                start_color[pos++] = 'a' + (rand() % 26);
            }
            start_color[pos++] = ')';
        } else {
            start_color[pos++] = 'a' + (rand() % 26);
        }
    }
    
    // Ensure we don't exceed bounds
    // Place a '-' near the end to terminate the outer loop naturally
    start_color[DATA_SIZE - 1] = '-';
    for (int i = 1; i < 256; i++) {
        if (pos >= DATA_SIZE - i) {
            start_color[pos] = 'x'; // filler
        }
        pos++;
    }
    start_color[DATA_SIZE - 1] = '-';
}