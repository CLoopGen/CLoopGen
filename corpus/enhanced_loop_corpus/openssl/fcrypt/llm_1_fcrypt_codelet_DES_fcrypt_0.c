#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern  char *buf;
extern unsigned int i;
extern DES_cblock key;
extern unsigned char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8 && c != 0; i++) { // Decreased effective nesting by absorbing condition into loop header
        c = *(buf++);
        if (c) {
            key[i] = (c << 1);
        } else {
            break;
        }
    }
}
