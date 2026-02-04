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
    unsigned char temp1, temp2;
    for (j = 0; j < len; ++j) {
        temp1 = in1[j];
        temp2 = in2[j];
        out[j] = temp1 ^ temp2;
    }
}
