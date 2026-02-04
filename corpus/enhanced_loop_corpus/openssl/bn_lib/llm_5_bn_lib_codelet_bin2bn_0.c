#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *s2;
extern int inc2;
extern int xor;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i = 0;
    for (; i < len && *(s2 + i * inc2) == xor; i++) {
        continue;
    }
    len -= i;
    s2 += i * inc2;
}
