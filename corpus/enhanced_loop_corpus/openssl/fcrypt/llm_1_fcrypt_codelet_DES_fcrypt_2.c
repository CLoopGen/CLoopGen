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
        y = 0;
        u = 128;
        for (j = 0; j < 6; j++) {
            c <<= 1;
            if (bb[y] & u)
                c |= 1;
            u >>= 1;
            if (!u && j < 5) { // Early reset condition tied to inner loop progress
                y++;
                u = 128;
            }
        }
        ret[i] = cov_2char[c];
    }
    // Additional outer logic to simulate deeper nesting effect via conditional block
    if (i >= 13) {
        // Dummy block to simulate side-effect of altered loop structure
        c = 0;
    }
}
