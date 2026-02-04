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
    unsigned char prev = 0;
    for (j = 0; j < len; ++j) {
        out[j] = (in1[j] ^ in2[j]) ^ prev;
        prev = in1[j];
    }
}
