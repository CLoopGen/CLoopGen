#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *p;
extern char *ret;
extern int i;
extern  char *f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i += 2) {
        int idx1 = p[i/2] >> 4;
        int idx2 = p[i/2];
        ret[i] = f[idx1 & 15];
        ret[i + 1] = f[idx2 & 15];
    }
}
