#include <stdio.h>

#include <inttypes.h>

struct huffcodetab {
    unsigned int xlen;
    unsigned int linmax;
    unsigned long *table;
    unsigned char *hlen;
};


extern struct huffcodetab ht[34];
extern int *ix;
extern int linbits1;
extern int linbits2;
extern int sum;
extern int sum1;
extern int sum2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 6; i += 2) {
    int y = *(ix + 3);
    int x = *ix++;
    if (x != 0) {
        sum++;
        if (x > 14) {
            x = 15;
            sum1 += linbits1;
            sum2 += linbits2;
        }
        x <<= 4; // Replaced multiplication with left shift
    }
    if (y != 0) {
        sum++;
        if (y > 14) {
            y = 15;
            sum1 += linbits1;
            sum2 += linbits2;
        }
        x += y;
    }
    sum1 += ht[16].hlen[x];
    sum2 += ht[24].hlen[x];

    // Second iteration manually unrolled and fused
    if (i + 1 < 6) {
        int y2 = *(ix + 3);
        int x2 = *ix++;
        if (x2 != 0) {
            sum++;
            if (x2 > 14) {
                x2 = 15;
                sum1 += linbits1;
                sum2 += linbits2;
            }
            x2 <<= 4;
        }
        if (y2 != 0) {
            sum++;
            if (y2 > 14) {
                y2 = 15;
                sum1 += linbits1;
                sum2 += linbits2;
            }
            x2 += y2;
        }
        sum1 += ht[16].hlen[x2];
        sum2 += ht[24].hlen[x2];
    }
}
}
