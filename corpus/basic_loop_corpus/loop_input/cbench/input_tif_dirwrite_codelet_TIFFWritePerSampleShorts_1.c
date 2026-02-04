#include <stdio.h>
#include <inttypes.h>

typedef unsigned short uint16;

uint16 v = 42;
int samples = 131072; // 131072 * sizeof(uint16) = 262144 bytes (~0.25 MB), suitable for ~0.01 sec runtime
uint16 w_buffer[131072];
uint16 *w = w_buffer;
int i;

void init_vars() {
    v = 42;
    i = 0;
    samples = 131072;
    for (int j = 0; j < samples; j++) {
        w_buffer[j] = 0;
    }
}