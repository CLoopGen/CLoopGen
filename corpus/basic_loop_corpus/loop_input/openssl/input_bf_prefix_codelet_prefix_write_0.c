#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *out;
size_t outl;
size_t i;
char c;

static char data[1024 * 512]; // 512 KB of data

void init_vars() {
    outl = sizeof(data) - 1; // Leave space for null or newline
    out = data;

    // Fill with non-newline characters except possibly at the end
    memset(data, 'A', outl - 1);
    data[outl - 1] = '\n'; // Ensure loop stops before boundary
    data[outl] = '\0';

    i = 0;
    c = '\0';
}