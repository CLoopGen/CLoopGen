#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *out;
int *inp;
int i;

static int16_t *out_buf;
static int *inp_buf;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // 128 MB of input data
    inp_buf = (int*)malloc(data_size);
    out_buf = (int16_t*)malloc(data_size);
    
    if (!inp_buf || !out_buf) {
        exit(1);
    }

    for (size_t j = 0; j < data_size / sizeof(int); j++) {
        inp_buf[j] = (int)(j & 0x7FFF);
    }

    out = out_buf;
    inp = inp_buf;
    i = 0;
}