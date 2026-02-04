#include <stdio.h>

#include <inttypes.h>

extern unsigned char *k1;
extern  unsigned char *l;
extern int bl;
extern int i;
extern unsigned char c;
extern unsigned char cnext;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char prev_c = c;
    for (i = 0; i < bl - 1; i++) {
        unsigned char next_c = l[i + 1];
        k1[i] = (prev_c << 1) | (next_c >> 7);
        prev_c = next_c;
    }
    c = prev_c;
}
