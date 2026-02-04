#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned char pad[144];
extern unsigned char keytmp[144];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
for (i = 0; i < 72; i++) {
    pad[2*i]     = 92 ^ keytmp[2*i] ^ 0x55;
    pad[2*i + 1] = 92 ^ keytmp[2*i + 1] ^ 0xAA;
}
}
