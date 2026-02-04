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
        *p++ = (m1[i] == m2[i]) ? ' ' : '^';
        *p++ = (m1[i] == m2[i]) ? ' ' : '^';
        if (m1[i] != m2[i])
            diff = 1;
        if ((i % 8 == 7) & (i != j - 1))
            *p++ = ' ';
    }
}
