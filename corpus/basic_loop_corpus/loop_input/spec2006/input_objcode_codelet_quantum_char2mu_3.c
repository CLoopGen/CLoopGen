#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *buf;
int i;
int size;
unsigned long long mu;

void init_vars() {
    size = 1 << 20; // 1MB of data: ~0.01 sec on modern CPU
    buf = (unsigned char *)malloc(size);
    if (!buf) {
        size = 0;
        return;
    }
    for (int j = 0; j < size; j++) {
        buf[j] = (unsigned char)(j & 0xFF);
    }
    mu = 0;
}