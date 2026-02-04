#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *p;
extern char *ret;
extern int i;
extern  char *f;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 8; i++) {
    ret[i * 2] = f[(p[i] >> 4) & 15];
    ret[i * 2 + 1] = f[p[i] & 15];
}

}
