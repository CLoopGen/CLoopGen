#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *s2;
extern int inc2;
extern int xor;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len <= 0) return;
    for (; *s2 == xor; s2 += inc2, len--) {
        if (len == 1) break;
        len--;
        if (len <= 0) break;
    }
}
