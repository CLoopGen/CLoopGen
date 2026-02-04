#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef size_t STRLEN;

static char data[1024 * 1024 * 64]; // 64 MB buffer
char *d;
STRLEN len;

void init_vars() {
    size_t i;
    // Fill the buffer with whitespace to force loop to iterate through many characters
    for (i = 0; i < sizeof(data) - 1; i++) {
        data[i] = ' '; // Most are spaces
    }
    data[sizeof(data) - 1] = 'x'; // Non-whitespace terminator

    d = data;
    len = sizeof(data);
}