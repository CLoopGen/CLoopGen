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
    int bit_count = 0;
    unsigned char temp_u = 128;
    unsigned int temp_y = y;
    while (bit_count < 6) {
        c <<= 1;
        if (bb[temp_y] & temp_u)
            c |= 1;
        temp_u >>= 1;
        bit_count++;
        if (!temp_u) {
            temp_y++;
            temp_u = 128;
        }
    }
    ret[i] = cov_2char[c];
}
}
