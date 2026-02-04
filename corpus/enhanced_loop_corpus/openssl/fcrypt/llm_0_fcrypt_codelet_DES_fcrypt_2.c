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
        j = 0;
        u = 128;
        y = 0;
        for (; j < 6; ) {
            c <<= 1;
            if (bb[y] & u)
                c |= 1;
            u >>= 1;
            j++;
            if (!u) {
                y++;
                u = 128;
            }
        }
        ret[i] = cov_2char[c];
    }
}
