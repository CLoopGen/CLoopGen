#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Jpeg2000QuantStyle {
    uint8_t expn[99];
    uint16_t mant[99];
    uint8_t quantsty;
    uint8_t nguardbits;
} Jpeg2000QuantStyle;

Jpeg2000QuantStyle *q;
int i;

void init_vars() {
    q = (Jpeg2000QuantStyle*)malloc(sizeof(Jpeg2000QuantStyle));
    if (!q) {
        exit(1);
    }

    for (int j = 0; j < 99; j++) {
        q->expn[j] = (uint8_t)(j * 7 + 3); 
        q->mant[j] = (uint16_t)(j * 13 + 5); 
    }
    q->quantsty = 1;
    q->nguardbits = 2;

    i = 0;
}