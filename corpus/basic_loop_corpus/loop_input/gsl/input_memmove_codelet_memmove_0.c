#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int length = 1 << 20; // 1MB of data for sufficient runtime (~0.01 sec on modern CPU)

char *source;
char *dest;

static char *source_buf;
static char *dest_buf;

void init_vars() {
    source_buf = (char *)calloc(length, sizeof(char));
    dest_buf = (char *)calloc(length, sizeof(char));

    if (!source_buf || !dest_buf) {
        exit(1);
    }

    for (unsigned int i = 0; i < length; ++i) {
        source_buf[i] = (char)(i & 0xFF);
    }

    source = source_buf + length;
    dest = dest_buf + length;
}