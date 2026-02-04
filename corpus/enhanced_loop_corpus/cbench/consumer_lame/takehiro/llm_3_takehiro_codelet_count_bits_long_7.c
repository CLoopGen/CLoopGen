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
    int base = i - 4;
    const int offsets[] = {3, 2, 1, 0}; // Strided access pattern with reverse offset indexing
    if ((unsigned int)(ix[base + offsets[0]] | ix[base + offsets[1]] | 
                       ix[base + offsets[2]] | ix[base + offsets[3]]) > 1)
        break;
    v = ix[base + offsets[0]];
    p = v;
    bits += v;
    v = ix[base + offsets[1]];
    if (v != 0) {
        p += 2;
        bits++;
    }
    v = ix[base + offsets[2]];
    if (v != 0) {
        p += 4;
        bits++;
    }
    v = ix[base + offsets[3]];
    if (v != 0) {
        p += 8;
        bits++;
    }
    a1 += ht[32].hlen[p];
}
}
