#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 128 * 1024 * 1024; // 128 MB to target ~0.01 sec runtime on modern CPU
    s = (char*)malloc(len);
    if (!s) {
        exit(1);
    }
    // Initialize all but the last byte to non-zero, ensuring loop stops at the null terminator
    for (size_t j = 0; j < len - 1; j++) {
        s[j] = 'a';
    }
    s[len - 1] = '\0'; // Ensure loop terminates here
}

void loop(); // Forward declaration to avoid implicit declaration

// Ensure that when linked with the loop function, calls are valid