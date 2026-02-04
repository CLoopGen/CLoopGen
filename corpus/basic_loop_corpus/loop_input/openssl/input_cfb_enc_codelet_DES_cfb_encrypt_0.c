#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int num;
int i;
int rem;
unsigned char *ovec;

void init_vars() {
    num = 64;
    rem = 3;
    size_t data_size = 1024 * 128; // 128KB of data
    ovec = (unsigned char *)malloc(data_size);
    for (size_t idx = 0; idx < data_size; ++idx) {
        ovec[idx] = (unsigned char)(idx & 0xFF);
    }
}