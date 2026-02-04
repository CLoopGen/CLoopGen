#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char *out;
extern unsigned char ivec[16];
extern int n;
extern int num;
extern unsigned char ovec[33];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (n = 0; n < num; ++n)
    out[n] = (ovec[16 + n] = in[n] ^ ivec[n]);

}
