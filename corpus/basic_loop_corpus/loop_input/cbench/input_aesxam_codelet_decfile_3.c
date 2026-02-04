#include <stdio.h>
#include <inttypes.h>

char inbuf1[16] = {0};
char outbuf[16] = {0};
int i = 0;

void init_vars() {
    for (int j = 0; j < 16; ++j) {
        inbuf1[j] = (char)(j * 7);
        outbuf[j] = (char)(j * 13);
    }
    i = 0;
}