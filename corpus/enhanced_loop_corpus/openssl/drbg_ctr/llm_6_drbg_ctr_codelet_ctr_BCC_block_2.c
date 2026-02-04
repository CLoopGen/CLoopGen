#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern  unsigned char *in;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp;
    for (i = 0; i < len; i++) {
        temp = in[i];
        out[i] ^= temp;
    }
}
