#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

unsigned char cov_2char[64];
char *ret;
unsigned int i;
unsigned int j;
unsigned int y;
unsigned char bb[9];
unsigned char c;
unsigned char u;

void init_vars() {
    for (int idx = 0; idx < 64; idx++) {
        cov_2char[idx] = (unsigned char)('A' + (idx % 26));
    }
    ret = (char*)malloc(13 * sizeof(char));
    i = 0;
    j = 0;
    y = 0;
    for (int idx = 0; idx < 9; idx++) {
        bb[idx] = (unsigned char)(123 - idx);
    }
    c = 0;
    u = 128;
}