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
    int limit = (nb + i < 8) ? nb + i : 7;
    for (j = i; j <= limit; j++) {
        uint32_t product = a.v[i] * (unsigned int)b.v[j - i];
        carry += out.v[j] + product;
        out.v[j] = (uint16_t)(carry & 0xFFFF);
        carry = (carry & 0xFFFF0000) >> 16;
    }
    // Carry propagation beyond the loop is dropped (no WAW on outer loop)
}
}
