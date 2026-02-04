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
int start = 14;
for (i = start; i >= 0; i -= 2) {
    carry_next = in[i] >> (8 - shift);
    out[i] = (in[i] << shift) | carry;
    carry = carry_next;

    if (i - 1 >= 0) {
        unsigned char temp_next = in[i-1] >> (8 - shift);
        out[i-1] = (in[i-1] << shift) | carry;
        carry = temp_next;
    }
}
}
