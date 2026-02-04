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
for (i = 0; i < na; i++) {
    unsigned int carry = 0;
    for (int k = 0; k <= nb && i + k < 8; k++) {
        j = i + k;
        if (a.v[i]) {
            carry = (carry >> 16) + out.v[j] + a.v[i] * (unsigned int)b.v[k];
            out.v[j] = carry;
        }
    }
}
}
