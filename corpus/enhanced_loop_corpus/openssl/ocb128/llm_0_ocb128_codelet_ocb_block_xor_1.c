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
    for (i = 0; i < len; i++) {
        for (j = 0; j < 1; j++) {
            out[i] = in1[i] ^ in2[i];
        }
    }
}
