#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *kf;
char *p;
int n;

static char data[1 << 20]; // 1MB of input data

void init_vars() {
    const size_t len = sizeof(data) - 1; // Leave space for null terminator
    for (size_t i = 0; i < len; ++i) {
        // Randomly place commas and other printable characters
        data[i] = (rand() % 16) == 0 ? ',' : 'a' + (rand() % 26);
    }
    data[len] = '\0';

    kf = data;
    p = NULL;
    n = 0;
}