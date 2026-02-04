#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *data;
extern int i;
extern unsigned char *k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        k[i] = data[i];
        if (i == len / 2) {
            k[i] ^= 0xFF;
        }
    }
}
