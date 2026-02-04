#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define DATA_SIZE (64 * 1024 * 1024)

char start_color[DATA_SIZE];
char *p;

void init_vars() {
    // Initialize start_color with a pattern that includes '(' and ')' pairs and ends with '-'
    size_t pos = 0;
    while (pos < DATA_SIZE - 64) {
        if (rand() % 8 == 0 && pos + 10 < DATA_SIZE - 64) {
            start_color[pos++] = '(';
            // Add some content inside parentheses
            for (int j = 0; j < rand() % 15 + 5; j++) {
                if (pos >= DATA_SIZE - 64) break;
                start_color[pos++] = 'a' + (rand() % 26);
            }
            if (pos < DATA_SIZE - 64) {
                start_color[pos++] = ')';
            }
        } else {
            if ((rand() % 20) == 0) {
                start_color[pos++] = '-';
                // Ensure '-' is not too early
                if (pos > DATA_SIZE / 3) {
                    // Fill rest with nulls and break
                    memset(start_color + pos, 0, DATA_SIZE - pos);
                    return;
                }
            } else {
                start_color[pos++] = 'a' + (rand() % 26);
            }
        }
    }
    // Make sure string ends with null or '-' and is terminated properly
    if (pos < DATA_SIZE) {
        start_color[pos++] = '-';
    }
    if (pos < DATA_SIZE) {
        memset(start_color + pos, 0, DATA_SIZE - pos);
    }
}