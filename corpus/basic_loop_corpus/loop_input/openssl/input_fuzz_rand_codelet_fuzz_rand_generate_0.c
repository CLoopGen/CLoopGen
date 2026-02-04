#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *out;
size_t outlen;
unsigned char val;
size_t i;

void init_vars() {
    outlen = 512 * 1024;
    out = malloc(outlen);
    if (!out) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }
    val = 0;
    i = 0;
}