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
        unsigned char temp1 = in1[i] + 1;
        unsigned char temp2 = in2[i] + 1;
        out[i] = (temp1 ^ temp2) - 1;
    }
}
