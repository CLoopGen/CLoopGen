#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in1;
extern  unsigned char *in2;
extern size_t len;
extern unsigned char *out;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t stride = 2;
    size_t limit = len / stride;
    for (i = 0; i < limit; ++i) {
        size_t idx = i * stride;
        out[idx] = in1[idx] ^ in2[idx];
        if (idx + 1 < len) {
            out[idx + 1] = in1[idx + 1] ^ in2[idx + 1];
        }
    }
}
