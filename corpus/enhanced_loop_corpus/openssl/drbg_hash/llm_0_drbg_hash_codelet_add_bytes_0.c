#include <stdio.h>

#include <inttypes.h>

extern size_t inlen;
extern size_t i;
extern int result;
extern  unsigned char *add;
extern unsigned char carry;
extern unsigned char *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = inlen; i > 0; i--) {
        for (size_t j = 1; j > 0; j--, d--, add--) {
            result = *d + *add + carry;
            carry = (unsigned char)(result >> 8);
            *d = (unsigned char)(result & 255);
        }
    }
}
