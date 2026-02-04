#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *out;
unsigned char *in;
int len;
int i;

void init_vars() {
    len = 1024 * 512; // 512KB of data, reasonable for ~0.01 sec on modern CPU

    in = (unsigned char *)malloc(len * sizeof(unsigned char));
    out = (unsigned char *)malloc(len * sizeof(unsigned char));

    if (!in || !out) {
        exit(1);
    }

    // Initialize in with some data
    for (int j = 0; j < len; j++) {
        in[j] = (unsigned char)(j & 0xFF);
    }

    // Initialize out with some initial values
    for (int j = 0; j < len; j++) {
        out[j] = (unsigned char)((j + 32) & 0xFF);
    }
}