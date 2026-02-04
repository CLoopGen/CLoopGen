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
for (i = 15; i >= 0; i--) {
    carry_next = (in[i] >> (4 - (shift / 2))) & 0x0F;
    out[i] = (in[i] << (shift + (i % 2))) | (carry & 0xFF);
    carry = (carry_next << 4) | ((in[i] >> (8 - shift)) & 0x0F);
}
}
