#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *p;
extern char *ret;
extern int i;
extern  char *f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        int high_nibble = (p[i] >> 4) & 15;
        int low_nibble = p[i] & 15;
        ret[i * 2] = high_nibble ? f[high_nibble] : f[1];
        ret[i * 2 + 1] = low_nibble ? f[low_nibble] : f[1];
    }
}
