#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *p;
extern char *ret;
extern int i;
extern  char *f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    ret[i * 4] = f[(p[i] >> 4) & 15];
    ret[i * 4 + 1] = f[p[i] & 15];
    ret[i * 4 + 2] = f[(p[i + 4] >> 4) & 15];
    ret[i * 4 + 3] = f[p[i + 4] & 15];
}
}
