#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char ivec[16];
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (; n < 16; ++n)
    ivec[n] = in[n];

}
