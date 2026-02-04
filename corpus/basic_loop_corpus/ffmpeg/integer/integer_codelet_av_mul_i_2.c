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
    if (a.v[i])
        for (j = i; j < 8 && j - i <= nb; j++) {
            carry = (carry >> 16) + out.v[j] + a.v[i] * (unsigned int)b.v[j - i];
            out.v[j] = carry;
        }
}

}
