#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[268435456]; // 256MB buffer
char *p;

void init_vars() {
    size_t size = sizeof(start_color) - 1; // Leave space for null terminator
    char *ptr = start_color;
    size_t i = 0;

    while (i < size - 100) {
        // Randomly decide whether to insert a parenthesized group or plain characters
        if (rand() % 5 == 0 && i + 10 < size) {
            ptr[i++] = '(';
            // Fill inside with non-) non-null chars
            while (i < size - 1 && ptr[i] != ')' && ptr[i] != '\x00') {
                ptr[i++] = 'a' + (rand() % 26);
                if (rand() % 20 == 0) break; // Random length
            }
            if (i < size) ptr[i++] = ')';
        } else {
            // Normal character, avoid '-' and '\0' until the end
            if (rand() % 100 == 0) {
                ptr[i++] = '-';
                break;
            } else {
                ptr[i++] = 'a' + (rand() % 26);
            }
        }
    }

    // Ensure termination by '-' or '\0' at the end
    if (i >= size) {
        ptr[size-1] = '\0';
    } else {
        ptr[i] = '-'; // Will cause loop to exit naturally
        ptr[i+1] = '\0';
    }

    p = start_color; // Initial value for p
}