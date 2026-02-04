#include <stdint.h>
#include <stdlib.h>
#include <string.h>

unsigned char *out;
size_t bits;
unsigned int len;
int i;

void init_vars() {
    len = 262144; // 256KB of data to target ~0.01 sec runtime
    out = (unsigned char *)malloc(len * sizeof(unsigned char));
    if (!out) {
        len = 0;
        return;
    }
    bits = 0xABCDEF9876543210ULL; // Arbitrary large value for bit shifting
}