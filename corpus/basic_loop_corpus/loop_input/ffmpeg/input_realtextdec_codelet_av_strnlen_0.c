#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 131072; // Approximately 128KB data to target ~0.01s runtime
    s = (char*)malloc(len);
    if (!s) {
        exit(1);
    }
    for (size_t j = 0; j < len - 1; j++) {
        s[j] = 'x'; // Non-zero to keep loop condition active
    }
    s[len - 1] = '\0'; // Ensure loop terminates at last element
}