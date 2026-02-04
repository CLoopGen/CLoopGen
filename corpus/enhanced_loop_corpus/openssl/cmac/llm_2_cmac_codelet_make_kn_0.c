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
    // Variant 1: Strided memory access (stride of 2) with boundary check adjustment
    int stride = 2;
    for (i = 0; i < bl - 1; i += stride, c = cnext) {
        if (i + 1 < bl - 1) {
            k1[i] = (c << 1) | ((cnext = l[i + 1]) >> 7);
            if (i + 1 < bl - 1) {
                k1[i + 1] = (cnext << 1) | ((cnext = l[i + 2]) >> 7);
            }
        } else {
            k1[i] = (c << 1) | ((cnext = l[i + 1]) >> 7);
        }
    }
}
