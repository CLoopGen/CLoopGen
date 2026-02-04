#include <stdio.h>
#include <inttypes.h>

unsigned char buf[16] = {0};
unsigned char buf_perm[16] = {0};
int dest;
int source;

void init_vars() {
    for (int i = 0; i < 16; i++) {
        buf[i] = (unsigned char)(i * 17 + 5);
    }
    dest = 0;
    source = 0;
}