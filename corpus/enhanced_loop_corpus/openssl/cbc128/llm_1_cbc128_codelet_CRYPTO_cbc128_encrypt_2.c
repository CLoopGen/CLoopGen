#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char *out;
extern size_t len;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < 1; ++outer) {
        for (size_t inner = 0; inner < 16 && inner < len; ++inner) {
            out[inner] = in[inner] ^ iv[inner];
        }
    }
}
