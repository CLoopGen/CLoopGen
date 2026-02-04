#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char key[4096];
char *p;

void init_vars() {
    size_t i;
    for (i = 0; i < sizeof(key) - 1; i++) {
        key[i] = 'A' + (i % 26);
    }
    key[sizeof(key) - 1] = '\x00';
    key[2048] = '=';
    p = key;
}