#include <stdio.h>

#include <inttypes.h>

typedef size_t size_t_aX __attribute__((aligned(1)));

extern  unsigned char *in;
extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 16; n += 2) {
        out[n] = in[n] ^ iv[n];
        if (n + 1 < 16) {
            out[n + 1] = in[n + 1] ^ iv[n + 1];
        }
    }
}
