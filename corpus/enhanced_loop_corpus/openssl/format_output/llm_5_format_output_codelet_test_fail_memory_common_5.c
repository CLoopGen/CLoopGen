#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *m1;
extern  unsigned char *m2;
extern char *p;
extern size_t i;
extern unsigned int diff;
extern  size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < j; i++) {
        unsigned char eq = (m1[i] == m2[i]);
        diff |= !eq;
        *p++ = eq ? ' ' : '^';
        *p++ = eq ? ' ' : '^';
        if ((i & 7) == 7 && i + 1 < j)
            *p++ = ' ';
    }
}
