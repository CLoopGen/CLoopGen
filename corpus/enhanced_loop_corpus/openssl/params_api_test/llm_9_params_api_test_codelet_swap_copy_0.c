#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern  void *in;
extern size_t len;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t unroll_factor = 4;
    size_t remainder = len % unroll_factor;
    for (j = 0; j < remainder; j++) {
        out[j] = ((unsigned char *)in)[len - j - 1];
    }
    for (; j + (unroll_factor - 1) < len; j += unroll_factor) {
        out[j]     = ((unsigned char *)in)[len - j - 1];
        out[j + 1] = ((unsigned char *)in)[len - j - 2];
        out[j + 2] = ((unsigned char *)in)[len - j - 3];
        out[j + 3] = ((unsigned char *)in)[len - j - 4];
    }
}
