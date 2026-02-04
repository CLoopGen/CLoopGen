#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *e;
char *p;

static char data[1 << 24]; // 16 MB buffer

void init_vars() {
    size_t i;
    size_t len = sizeof(data) - 1; // Leave space for null terminator

    // Initialize with printable characters, avoiding whitespace
    for (i = 0; i < len - 1; i++) {
        data[i] = 'a' + (i % 26);
    }

    // Place a whitespace character near the end to stop the loop
    data[len - 1] = ' ';

    // Null terminate
    data[len] = '\0';

    // Initialize p to point to the start of data
    p = data;

    // Initialize e to match p (will be updated in loop)
    e = p;
}