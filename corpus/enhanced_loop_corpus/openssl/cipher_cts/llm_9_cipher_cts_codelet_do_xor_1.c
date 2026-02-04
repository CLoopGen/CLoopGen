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
    unsigned char temp1, temp2, temp3, temp4;
    for (i = 0; i < len; i++) {
        temp1 = in1[i] ^ in2[i];
        temp2 = temp1 + 1;
        temp3 = temp2 ^ 0xFF;
        temp4 = temp3 - 1;
        out[i] = temp4;
    }
}
