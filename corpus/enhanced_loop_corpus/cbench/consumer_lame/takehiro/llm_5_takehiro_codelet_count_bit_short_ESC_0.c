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
for (i = 0; i < 3; i++) {
    int y = *(ix + 3);
    int x = *ix++;
    sum += (x != 0) ? 1 : 0;
    if (x > 14) {
        x = 15;
        sum1 += linbits1;
        sum2 += linbits2;
    } else if (x == 0) {
        if (y != 0) {
            sum++;
            if (y > 14) {
                y = 15;
                sum1 += linbits1;
                sum2 += linbits2;
            }
            x = y;
        } else {
            sum1 += ht[16].hlen[0];
            sum2 += ht[24].hlen[0];
            continue;
        }
    } else {
        x *= 16;
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
}
}
