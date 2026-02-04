#include <stdio.h>

#include <inttypes.h>

extern  unsigned char key_table[256];
extern int len;
extern int i;
extern int j;
extern unsigned char *k;
extern unsigned int d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = len; i < 64; i += 2, j++) {
        unsigned int temp1 = (k[j] + d) & 255;
        unsigned int temp2 = (k[j] + d + 1) & 255;
        d = key_table[temp1];
        k[i] = d;
        k[i + 1] = key_table[temp2];
        d ^= k[j];
    }
}
