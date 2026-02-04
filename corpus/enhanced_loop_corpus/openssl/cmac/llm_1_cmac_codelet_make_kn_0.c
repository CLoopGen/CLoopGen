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
    for (i = 0; i < (bl - 1) && bl > 0; i++) {
        unsigned char temp_cnext = l[i + 1];
        k1[i] = (c << 1) | (temp_cnext >> 7);
        c = temp_cnext;
    }
}
