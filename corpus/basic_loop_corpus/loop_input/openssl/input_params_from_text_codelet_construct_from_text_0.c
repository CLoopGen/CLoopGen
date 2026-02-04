#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

void *buf;
unsigned char *cp;
size_t i;

static unsigned char data[131072]; // 128KB buffer

void init_vars() {
    buf = data;
    cp = data;
    i = 131072;
    memset(data, 0, 131072);
}