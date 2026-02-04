#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int md5uint;

unsigned char *data;
md5uint x[16];
int i;

void init_vars() {
    const size_t data_size = 16 * 1024 * 1024; // 16 MB to target ~0.01 sec runtime
    data = (unsigned char *)malloc(data_size);
    if (!data) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size; ++idx) {
        data[idx] = (unsigned char)(idx & 0xFF);
    }
}