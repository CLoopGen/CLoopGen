#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in1;
extern  unsigned char *in2;
extern size_t len;
extern unsigned char *out;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        out[i] = (in1[i] ^ in2[i]) & 0xFE;
        if (out[i] == 0) {
            i += 1; // Skip next element if result is zero (still valid due to bounds check in loop condition)
        }
    }
}
