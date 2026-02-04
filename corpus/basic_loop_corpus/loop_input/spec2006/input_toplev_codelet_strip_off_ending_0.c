#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *name;
int len;
int i;

void init_vars() {
    len = 1 << 20; // Approximately 1MB data size
    name = (char *)malloc(len + 1);
    if (!name) {
        exit(1);
    }
    memset(name, 'a', len);
    name[len] = '\x00';

    int pos = 4;
    if (pos < len) {
        name[len - pos] = '.';
    }

    i = 0;
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}