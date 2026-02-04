#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024)

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with a pattern that triggers the loop logic
    // Fill with printable characters, including '(' and ')' pairs, and terminate with '-'
    size_t pos = 0;
    while (pos < sizeof(start_color) - 64) {
        if (rand() % 20 == 0) {
            start_color[pos++] = '(';
            while (pos < sizeof(start_color) - 64 && rand() % 15 != 0) {
                start_color[pos++] = 'a' + (rand() % 26);
            }
            if (pos < sizeof(start_color)) {
                start_color[pos++] = ')';
            }
        } else {
            start_color[pos++] = 'a' + (rand() % 26);
        }
    }

    // Ensure we don't exceed buffer; place '-' near the end to stop outer loop
    if (pos >= sizeof(start_color)) pos = sizeof(start_color) - 1;
    start_color[pos] = '-';

    // Initialize p to point to start of start_color
    p = start_color;

    // Warm up or stabilize state if needed
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&p));
}