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
    for (; i < j; i += 2) {
        if (i + 1 < j) {
            if (m1[i] == m2[i]) {
                *p++ = ' ';
                *p++ = ' ';
            } else {
                *p++ = '^';
                *p++ = '^';
                diff = 1;
            }
            if (m1[i+1] == m2[i+1]) {
                *p++ = ' ';
                *p++ = ' ';
            } else {
                *p++ = '^';
                *p++ = '^';
                diff = 1;
            }
            if ((i + 1) % 8 == 7 && i + 1 != j - 1)
                *p++ = ' ';
        } else {
            if (m1[i] == m2[i]) {
                *p++ = ' ';
                *p++ = ' ';
            } else {
                *p++ = '^';
                *p++ = '^';
                diff = 1;
            }
        }
    }
}
