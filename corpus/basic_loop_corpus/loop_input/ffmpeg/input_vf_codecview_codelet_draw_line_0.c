#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int ex = 1023;
int stride = 1024;
int color = 128;
int x;
int y;
int fr;
int f = 65536;

void init_vars() {
    buf = aligned_alloc(32, (size_t)stride * (ex + 2) + 32);
    if (!buf) {
        exit(1);
    }
}