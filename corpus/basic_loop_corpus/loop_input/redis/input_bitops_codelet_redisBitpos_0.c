#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long count;
unsigned long *l;
unsigned char *c;
unsigned long word;
unsigned long j;

static unsigned char data[1 << 24]; // ~16.7 MB to ensure loop runtime ~0.01s

void init_vars() {
    word = 0xABCDEF00UL;
    count = sizeof(data);
    c = data;
    for (size_t i = 0; i < sizeof(data); i++) {
        data[i] = (unsigned char)(i & 0xFF);
    }
    l = &word;
    j = 0;
}