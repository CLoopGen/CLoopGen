#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in1;
extern  unsigned char *in2;
extern size_t len;
extern unsigned char *out;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < len; i += 2) {
        out[i] = in1[i] ^ in2[i];
        if (i + 1 < len) {
            out[i + 1] = in1[i + 1] ^ in2[i + 1];
        }
    }
}
