#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB for ~0.01 sec runtime

char start_color[4096];
char *p;

static char data_buffer[DATA_SIZE];

void init_vars() {
    // Initialize start_color as a circular buffer of characters with embedded parentheses and terminator
    // Fill start_color with a pattern that includes '(' and ')' pairs, '-' and null terminator at the end
    for (int i = 0; i < 4095; i++) {
        switch (i % 23) {
            case 0:
                start_color[i] = '(';
                break;
            case 7:
                start_color[i] = '-';
                break;
            case 13:
                start_color[i] = ')';
                break;
            default:
                start_color[i] = 'a' + (i % 26);
                break;
        }
    }
    start_color[4095] = '\0'; // Ensure null termination

    // Initialize p to point to start of start_color
    p = start_color;

    // Initialize large data buffer to ensure memory safety if accessed indirectly
    memset(data_buffer, 'x', DATA_SIZE);
    data_buffer[DATA_SIZE - 1] = '\0';
}