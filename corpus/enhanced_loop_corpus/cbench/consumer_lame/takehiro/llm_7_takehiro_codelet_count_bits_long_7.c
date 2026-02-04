#include <stdio.h>

#include <inttypes.h>

struct huffcodetab {
    unsigned int xlen;
    unsigned int linmax;
    unsigned long *table;
    unsigned char *hlen;
};


extern struct huffcodetab ht[34];
extern int ix[576];
extern int i;
extern int a1;
extern int bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int local_bits = bits;
int local_a1 = a1;
for (; i > 3; i -= 4) {
    int p, v;
    if ((unsigned int)(ix[i - 1] | ix[i - 2] | ix[i - 3] | ix[i - 4]) > 1)
        break;
    v = ix[i - 1];
    p = v;
    local_bits += v;
    v = ix[i - 2];
    if (v != 0) {
        p += 2;
        local_bits++;
    }
    v = ix[i - 3];
    if (v != 0) {
        p += 4;
        local_bits++;
    }
    v = ix[i - 4];
    if (v != 0) {
        p += 8;
        local_bits++;
    }
    local_a1 += ht[32].hlen[p];
}
bits = local_bits;
a1 = local_a1;
}
