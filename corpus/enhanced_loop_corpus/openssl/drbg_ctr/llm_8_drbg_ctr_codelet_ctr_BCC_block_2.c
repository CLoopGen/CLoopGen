#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern  unsigned char *in;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            out[i] ^= in[i] + 1;
            out[i+1] ^= in[i+1] - 1;
        } else {
            out[i] ^= in[i];
        }
    }
}
