#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern  char *buf;
extern unsigned int i;
extern DES_cblock key;
extern unsigned char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i += 2) {
        c = *(buf++);
        if (!c)
            break;
        key[i] = (c << 1) + 3;
        if (i + 1 < 8) {
            c = *(buf++);
            if (!c) break;
            key[i+1] = (c << 1) + 5;
        }
    }
}
