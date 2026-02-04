#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int int32;
typedef unsigned int uint32;

char *key;
char *cp;
char c;
int32 s;
uint32 hash;

static char key_buffer[1 << 20]; // 1MB buffer

void init_vars() {
    size_t i;
    size_t len = sizeof(key_buffer) - 1; // Leave space for null terminator

    for (i = 0; i < len; i++) {
        key_buffer[i] = 'a' + (i % 26);
    }
    key_buffer[len] = '\0';

    key = key_buffer;
    cp = key;
    c = 0;
    s = 0;
    hash = 0;
}