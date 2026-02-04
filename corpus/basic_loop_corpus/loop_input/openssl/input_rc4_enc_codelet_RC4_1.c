#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

unsigned char *indata;
unsigned char *outdata;
unsigned int *d;
unsigned int x;
unsigned int y;
unsigned int tx;
unsigned int ty;
size_t i;

void init_vars() {
    const size_t data_size = 262144; // 256KB input for ~0.01 sec runtime estimate

    indata = (unsigned char *)malloc(data_size * sizeof(unsigned char));
    outdata = (unsigned char *)malloc(data_size * sizeof(unsigned char));
    d = (unsigned int *)malloc(256 * sizeof(unsigned int));

    if (!indata || !outdata || !d) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        indata[idx] = (unsigned char)(idx & 0xFF);
    }
    memset(outdata, 0, data_size);

    for (int idx = 0; idx < 256; ++idx) {
        d[idx] = idx;
    }

    x = 0;
    y = 0;
    tx = 0;
    ty = 0;
    i = data_size / 8; // Each iteration processes up to 8 elements
}