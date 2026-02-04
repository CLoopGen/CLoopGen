#include <stdio.h>

#include <inttypes.h>

extern unsigned char *k1;
extern  unsigned char *l;
extern int bl;
extern int i;
extern unsigned char c;
extern unsigned char cnext;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp;
    for (i = 0; i < (bl > 10 ? 10 : bl - 1); i++) {
        temp = l[i + 1];
        k1[i] = ((c & 1) ^ (temp & 1)) ? (c << 1) | (temp >> 7) : (c >> 1) | (temp << 7);
        c = temp;
    }
}
