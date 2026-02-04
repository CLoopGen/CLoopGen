#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVInteger {
    uint16_t v[8];
} AVInteger;

extern AVInteger a;
extern AVInteger b;
extern AVInteger out;
extern int i;
extern int j;
extern int na;
extern int nb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < na; i += 2) {
    unsigned int carry0 = 0, carry1 = 0;
    if (a.v[i]) {
        for (j = i; j < 8 && j - i <= nb; j++) {
            carry0 = (carry0 >> 16) + out.v[j] + a.v[i] * (unsigned int)b.v[j - i];
            out.v[j] = carry0;
        }
    }
    if (i + 1 < na && a.v[i + 1]) {
        for (j = i + 1; j < 8 && j - (i + 1) <= nb; j++) {
            carry1 = (carry1 >> 16) + out.v[j] + a.v[i + 1] * (unsigned int)b.v[j - (i + 1)];
            out.v[j] = carry1;
        }
    }
}
}
