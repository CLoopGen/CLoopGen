#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *buf;
int i;
int size;
int j;

void init_vars() {
    size = 1 << 20; // 1MB of data: ~0.01 sec on modern CPU
    buf = (unsigned char *)malloc(size);
    if (!buf) {
        size = 0;
        j = 0;
        return;
    }
    for (int idx = 0; idx < size; idx++) {
        buf[idx] = (unsigned char)(idx & 0xFF);
    }
    i = size - 1;
    j = 0;
}