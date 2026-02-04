#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

char *name;
char *leaf;
char *sep;
char *p;

static char data[1 << 20]; // 1MB buffer

void init_vars() {
    name = data;
    leaf = NULL;
    sep = NULL;
    p = NULL;

    size_t len = sizeof(data) - 1;
    for (size_t i = 0; i < len; i++) {
        data[i] = 'a';
    }
    data[len] = '\0';

    // Place a few separators to ensure branches are taken
    if (len > 100) {
        data[100] = '\'';
        data[200] = ':';
        data[201] = ':';
        data[300] = '\'';
        data[400] = ':';
        data[401] = ':';
    }
}