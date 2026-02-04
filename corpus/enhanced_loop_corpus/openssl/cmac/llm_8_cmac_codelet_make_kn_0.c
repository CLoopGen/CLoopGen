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
    for (i = 0; i < bl - 2; i += 2, c = cnext) {
        k1[i] = (c << 1) | ((cnext = l[i + 1]) >> 7);
        if (i + 1 < bl - 1) {
            k1[i + 1] = (cnext << 1) | ((cnext = l[i + 2]) >> 7);
        }
    }
}
