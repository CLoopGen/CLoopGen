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
    unsigned char buffer[16];
    unsigned char prev_carry = carry;
    for (i = 15; i >= 0; i--) {
        buffer[i] = in[i] >> (8 - shift);
        out[i] = (in[i] << shift) | prev_carry;
        prev_carry = buffer[i];
    }
    carry = buffer[0];
}
