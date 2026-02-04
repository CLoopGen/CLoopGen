#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char key[1 << 20]; // 1MB size for ~0.01 sec runtime
char *p;

void init_vars() {
    // Initialize key with a long string without '=' until near the end to ensure loop runs long enough
    size_t size = sizeof(key);
    memset(key, 'A', size - 2);
    key[size - 2] = '=';
    key[size - 1] = '\x00'; // null terminate

    p = key; // initial value for p
}