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
    for (i = 1; i < len; i++) {
        out[i] = in1[i-1] ^ in2[i];
    }
    if (len > 0) {
        out[0] = in1[0] ^ in2[0];
    }
}
