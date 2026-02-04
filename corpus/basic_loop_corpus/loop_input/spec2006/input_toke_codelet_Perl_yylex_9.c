#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
char *d;

static char data[1 << 24]; // 16 MB

void init_vars() {
    // Initialize the data array with leading spaces and tabs
    size_t i;
    for (i = 0; i < sizeof(data) - 1024; i++) {
        data[i] = ' ';
    }
    for (; i < sizeof(data) - 1; i++) {
        data[i] = 'a'; // non-space to break the loop
    }
    data[sizeof(data) - 1] = '\0';

    s = data;
    d = s + 1;
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}