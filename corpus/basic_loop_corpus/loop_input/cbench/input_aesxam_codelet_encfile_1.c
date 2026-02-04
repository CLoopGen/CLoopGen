#include <stdio.h>
#include <inttypes.h>

char inbuf[16] = {0};
char outbuf[16] = {0};
unsigned long i = 0;

void init_vars() {
    for (size_t idx = 0; idx < 16; ++idx) {
        inbuf[idx] = (char)(idx & 0xFF);
        outbuf[idx] = (char)((idx * 3) & 0xFF);
    }
    i = 0;
}