#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern  char *buf;
extern unsigned int i;
extern DES_cblock key;
extern unsigned char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int j;
    for (i = 0; i < 8; i++) {
        j = i;
        c = buf[j];
        buf++; // Increment buf independently of index usage
        if (!c)
            break;
        key[i] = (c << 1);
    }
}
