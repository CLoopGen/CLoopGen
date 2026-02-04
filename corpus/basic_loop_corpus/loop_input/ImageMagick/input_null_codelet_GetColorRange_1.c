#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with data to ensure loop runs for desired time
    // We'll create a pattern that includes parentheses and non-terminating chars
    // Use about 4KB of data as defined by array size

    for (int i = 0; i < 4095; ) {
        if (i + 10 < 4095) {
            start_color[i] = '(';
            i++;
            while (i < 4095 - 1 && i % 7 != 0) { // Random-like closing every 7th group
                if ((i % 13) == 0) {
                    start_color[i] = '-';
                    break;
                }
                start_color[i] = 'a' + (i % 26);
                i++;
            }
            if (i < 4095 && start_color[i-1] != '-') {
                start_color[i] = ')';
                i++;
            }
        } else {
            start_color[i] = '\x00';
            break;
        }
    }
    start_color[4095] = '\x00'; // Ensure null termination

    // Initialize p to start of array
    p = start_color;
}