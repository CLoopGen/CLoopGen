#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char *out;
extern size_t len;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < len && n < 16; n += 2) {
        if (n + 1 < len && n + 1 < 16) {
            out[n] = in[n] ^ iv[n];
            out[n+1] = in[n+1] ^ iv[n+1];
        } else {
            out[n] = in[n] ^ iv[n];
        }
    }
}
