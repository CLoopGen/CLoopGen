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
    for (j = 0; j < len; j += 2) {
        if (j + 1 < len) {
            out[j] = in1[j] ^ in2[j];
            out[j + 1] = in1[j + 1] ^ in2[j + 1];
        } else {
            out[j] = in1[j] ^ in2[j];
        }
    }
}
