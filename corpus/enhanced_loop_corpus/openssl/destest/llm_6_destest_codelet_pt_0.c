#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *p;
extern char *ret;
extern int i;
extern  char *f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char temp_low, temp_high;
    for (i = 0; i < 8; i++) {
        temp_high = f[(p[i] >> 4) & 15];
        temp_low = f[p[i] & 15];
        ret[i * 2] = temp_high;
        ret[i * 2 + 1] = temp_low;
    }
}
