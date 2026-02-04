#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *s2;
extern int inc2;
extern int xor;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char local_xor = xor;
    int i;
    for (i = 0; i < len; i++) {
        unsigned char val = s2[i * inc2];
        if (val != local_xor) {
            len -= i;
            s2 += i * inc2;
            return;
        }
    }
    len = 0;
}
