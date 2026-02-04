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
    size_t unroll_factor = 4;
    size_t limit = j - (j % unroll_factor);
    for (; i < limit; i += unroll_factor) {
        for (size_t k = 0; k < unroll_factor; k++) {
            size_t idx = i + k;
            if (m1[idx] == m2[idx]) {
                *p++ = ' ';
                *p++ = ' ';
            } else {
                *p++ = '^';
                *p++ = '^';
                diff = 1;
            }
            if (idx % 8 == 7 && idx != j - 1)
                *p++ = ' ';
        }
    }
    for (; i < j; i++) {
        if (m1[i] == m2[i]) {
            *p++ = ' ';
            *p++ = ' ';
        } else {
            *p++ = '^';
            *p++ = '^';
            diff = 1;
        }
        if (i % 8 == 7 && i != j - 1)
            *p++ = ' ';
    }
}
