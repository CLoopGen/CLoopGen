#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern  char *buf;
extern unsigned int i;
extern DES_cblock key;
extern unsigned char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        c = buf[i];
        key[i] = ((c << 2) >> 1);
        key[7 - i] = ((buf[7 - i] << 1) ^ 0x0F);
    }
}
