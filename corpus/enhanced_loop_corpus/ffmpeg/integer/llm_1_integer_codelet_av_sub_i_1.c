#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVInteger {
    uint16_t v[8];
} AVInteger;

extern AVInteger a;
extern AVInteger b;
extern int i;
extern int carry;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        carry = (carry >> 16) + a.v[i] - b.v[i];
        a.v[i] = carry;
        carry = (carry >> 16) + a.v[i + 4] - b.v[i + 4];
        a.v[i + 4] = carry;
    }
}
