#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
char *w;
int level;

static char data[1 << 20]; // 1MB buffer

void init_vars() {
    s = data;
    level = 1;

    // Fill the buffer with a pattern that keeps level fluctuating but ends when level becomes 0
    size_t len = sizeof(data) - 1;
    int current_level = level;
    size_t i;

    for (i = 0; i < len - 1; i++) {
        if (current_level <= 1) {
            data[i] = '(';
            current_level++;
        } else if ((i % 7) == 0) {
            data[i] = ')';
            current_level--;
        } else {
            data[i] = 'a' + (i % 26);
        }
    }
    data[len - 1] = '\0'; // Ensure null terminator

    w = s + 2; // Initial value set before loop start
}