#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *d;
char *t;

static char data[1048576]; // 1MB buffer

void init_vars() {
    // Initialize the data array with spaces and tabs at the beginning, followed by non-whitespace
    size_t prefix_len = 100000; // Enough to take ~0.01s to scan on modern CPU
    size_t i;
    for (i = 0; i < prefix_len; i++) {
        data[i] = ' ';
    }
    // Add a tab and newline in the prefix for variety
    if (prefix_len > 1) data[prefix_len - 1] = '\t';
    if (prefix_len > 2) data[prefix_len - 2] = '\n';
    // Terminate the string after the prefix
    data[prefix_len] = 'A'; // Non-whitespace to stop the loop
    data[prefix_len + 1] = '\0';

    // Initialize d to point to the start of our data
    d = data;
    t = NULL; // Will be set in loop
}