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
for (i = 2; i < 13; i += 2) {
    c = 0;
    u = 128;
    y = 0;
    for (j = 0; j < 6; j++) {
        c <<= 1;
        if (bb[y] & u)
            c |= 1;
        u >>= 1;
        if (!u) {
            y++;
            u = 128;
        }
    }
    ret[i] = cov_2char[c];
    if (i + 1 < 13) {
        c = 0;
        u = 128;
        y = 0;
        for (j = 0; j < 6; j++) {
            c <<= 1;
            if (bb[y] & u)
                c |= 1;
            u >>= 1;
            if (!u) {
                y++;
                u = 128;
            }
        }
        ret[i + 1] = cov_2char[c];
    }
}
}
