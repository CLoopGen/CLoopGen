#include <stdio.h>

#include <inttypes.h>

extern  unsigned char cov_2char[64];
extern char *ret;
extern unsigned int i;
extern unsigned int j;
extern unsigned int y;
extern unsigned char bb[9];
extern unsigned char c;
extern unsigned char u;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < 13; i++) {
    c = 0;
    for (j = 0; j < 6; j++) {
        c <<= 1;
        c |= (bb[y] & u) ? 1 : 0;
        u >>= 1;
        y += (u == 0);
        u |= (u == 0) << 7;
    }
    ret[i] = cov_2char[c];
}
}
