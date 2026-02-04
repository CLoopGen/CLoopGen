#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in1;
extern  unsigned char *in2;
extern size_t len;
extern unsigned char *out;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            out[i]     = in1[i] ^ in2[i];
            out[i + 1] = in1[i + 1] ^ in2[i + 1];
        } else {
            out[i] = in1[i] ^ in2[i];
        }
    }
}
