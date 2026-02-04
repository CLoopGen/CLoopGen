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
for (; i > 3; i -= 4) {
    int p = 0, v;
    unsigned int val = (ix[i - 1] | ix[i - 2] | ix[i - 3] | ix[i - 4]);
    if (val > 1) continue;
    v = ix[i - 1];
    p = v;
    bits += v;
    v = ix[i - 2];
    if (v) {
        p += 2;
        bits++;
    }
    v = ix[i - 3];
    if (v) {
        p += 4;
        bits++;
    }
    v = ix[i - 4];
    if (v) {
        p += 8;
        bits++;
    }
    a1 += ht[32].hlen[p];
}
}
