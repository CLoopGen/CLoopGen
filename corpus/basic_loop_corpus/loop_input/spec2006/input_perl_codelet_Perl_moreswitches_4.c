#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *s;
static char *s_storage;

void init_vars() {
    size_t data_size = 16 * 1024 * 1024; // 16 MB for ~0.01 sec runtime
    s_storage = (char *)malloc(data_size);
    if (!s_storage) {
        exit(1);
    }

    // Fill with alphanumeric chars and underscores to keep loop running
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";
    int charset_len = sizeof(charset) - 1;

    for (size_t i = 0; i < data_size - 1; i++) {
        s_storage[i] = charset[rand() % charset_len];
    }
    // Ensure a non-alnum, non-underscore char at the end to terminate loop
    s_storage[data_size - 1] = ' ';

    // Initialize s to point near the beginning but allow s++ to happen
    s = s_storage + 1;
}