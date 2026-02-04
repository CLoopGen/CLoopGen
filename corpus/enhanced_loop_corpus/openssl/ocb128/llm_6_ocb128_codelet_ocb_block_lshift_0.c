#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern size_t shift;
extern unsigned char *out;
extern int i;
extern unsigned char carry;
extern unsigned char carry_next;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    carry_next = 0;
    for (i = 15; i >= 0; i--) {
        unsigned char temp = in[i] >> (8 - shift);
        out[i] = (in[i] << shift) | carry;
        carry = temp;
    }
}
