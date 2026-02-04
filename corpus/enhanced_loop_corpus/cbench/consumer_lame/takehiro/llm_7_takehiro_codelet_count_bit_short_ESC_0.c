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
int local_sum = 0, local_sum1 = 0, local_sum2 = 0;
for (i = 0; i < 3; i++) {
    int y = *(ix + 3);
    int x = *ix++;
    if (x != 0) {
        local_sum++;
        if (x > 14) {
            x = 15;
            local_sum1 += linbits1;
            local_sum2 += linbits2;
        }
        x *= 16;
    }
    if (y != 0) {
        local_sum++;
        if (y > 14) {
            y = 15;
            local_sum1 += linbits1;
            local_sum2 += linbits2;
        }
        x += y;
    }
    local_sum1 += ht[16].hlen[x];
    local_sum2 += ht[24].hlen[x];
}
sum += local_sum;
sum1 += local_sum1;
sum2 += local_sum2;
}
