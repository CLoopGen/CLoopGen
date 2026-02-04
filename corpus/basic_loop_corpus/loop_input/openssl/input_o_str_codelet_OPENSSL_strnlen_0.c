#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

char *str;
size_t maxlen;
char *p;

static char data[1024 * 512]; // 512KB buffer

void init_vars() {
    size_t i;
    // Initialize a large string with no null terminator in the middle
    for (i = 0; i < sizeof(data) - 1; i++) {
        data[i] = 'a'; // Fill with non-null characters
    }
    data[sizeof(data) - 1] = '\x00'; // Null terminate at the very end

    str = data;
    maxlen = sizeof(data);
    p = NULL;
}