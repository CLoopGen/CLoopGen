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
    // Add an outer loop that processes chunks of 8 elements, increasing loop nesting depth
    for (; i > 7; ) {
        // Process two groups of 4 in nested fashion
        for (int chunk = 0; chunk < 2 && i > 3; chunk++) {
            int p, v;
            if ((unsigned int)(ix[i - 1] | ix[i - 2] | ix[i - 3] | ix[i - 4]) > 1)
                goto exit_loop;
            v = ix[i - 1];
            p = v;
            bits += v;
            v = ix[i - 2];
            if (v != 0) {
                p += 2;
                bits++;
            }
            v = ix[i - 3];
            if (v != 0) {
                p += 4;
                bits++;
            }
            v = ix[i - 4];
            if (v != 0) {
                p += 8;
                bits++;
            }
            a1 += ht[32].hlen[p];
            i -= 4;
        }
    }
exit_loop:;
}
