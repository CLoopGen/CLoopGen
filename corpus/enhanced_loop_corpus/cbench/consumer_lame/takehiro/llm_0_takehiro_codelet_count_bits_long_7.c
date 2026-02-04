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
        int p, v;
        if ((unsigned int)(ix[i - 1] | ix[i - 2] | ix[i - 3] | ix[i - 4]) > 1)
            break;
        
        // Unroll the inner operations into a small loop to simulate increased nesting depth
        int j;
        p = 0;
        for (j = 0; j < 4; j++) {
            v = ix[i - 1 - j];
            if (v != 0) {
                p += (1 << j);
                bits++;
            } else if (j == 0) {
                p = v;  // v is 0 here, but matches original assignment
                bits += v;
            }
        }
        a1 += ht[32].hlen[p];
    }
}
