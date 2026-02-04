#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char b1[81] = {0};
char b2[81] = {0};
char *p;
size_t i;
unsigned int diff;
unsigned int real_diff;

static char buffer_storage[1024 * 1024];

void init_vars() {
    for (size_t idx = 0; idx < 80; ++idx) {
        b1[idx] = 'A' + (idx % 26);
        b2[idx] = 'A' + ((idx + 1) % 26);
    }
    b1[80] = '\x00';
    b2[80] = '\x00';

    p = buffer_storage;

    i = 0;
    diff = 0;
    real_diff = 0;
}