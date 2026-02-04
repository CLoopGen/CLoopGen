#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *name;
char *base;

static char data[1 << 20]; // 1MB buffer

void init_vars() {
    // Initialize the data array with a path-like string to ensure multiple '/' characters
    size_t len = sizeof(data) - 1; // Leave space for null terminator
    memset(data, 'a', len);
    // Place '/' at regular intervals to simulate a deep path
    for (size_t i = 1000; i < len; i += 1000) {
        data[i] = '/';
    }
    data[len] = '\0';

    // Initialize name to point to the start of data
    name = data;
    base = data; // Will be updated in the loop
}