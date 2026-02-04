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
for (; i > 7; i -= 8) {
    int p1, p2, v;
    unsigned int or_val = ix[i - 1] | ix[i - 2] | ix[i - 3] | ix[i - 4];
    unsigned int or_val2 = ix[i - 5] | ix[i - 6] | ix[i - 7] | ix[i - 8];
    if ((or_val | or_val2) > 1)
        break;
    
    // First group of 4
    p1 = v = ix[i - 1]; bits += v;
    v = ix[i - 2]; if (v != 0) { p1 += 2; bits++; }
    v = ix[i - 3]; if (v != 0) { p1 += 4; bits++; }
    v = ix[i - 4]; if (v != 0) { p1 += 8; bits++; }

    // Second group of 4
    p2 = v = ix[i - 5]; bits += v;
    v = ix[i - 6]; if (v != 0) { p2 += 2; bits++; }
    v = ix[i - 7]; if (v != 0) { p2 += 4; bits++; }
    v = ix[i - 8]; if (v != 0) { p2 += 8; bits++; }

    a1 += ht[32].hlen[p1] + ht[32].hlen[p2];
}
}
