#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *buf_in;
size_t i;
unsigned char ctmp;
size_t l;

void init_vars() {
    l = 512 * 1024; // 512 KB data size for ~0.01 sec runtime on modern CPU
    buf_in = (unsigned char *)malloc(l);
    if (!buf_in) {
        exit(1);
    }
    for (size_t idx = 0; idx < l; ++idx) {
        buf_in[idx] = (unsigned char)(idx & 0xFF);
    }
}