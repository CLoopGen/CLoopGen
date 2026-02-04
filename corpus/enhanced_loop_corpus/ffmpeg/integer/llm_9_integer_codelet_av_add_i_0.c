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
    for (i = 7; i >= 0; i--) {
        uint32_t temp1 = a.v[i] + b.v[i];
        uint32_t temp2 = temp1 + (carry & 0xFFFF);
        carry = (carry >> 16) + temp1 + (temp2 >> 16);
        a.v[i] = temp2 & 0xFFFF;
        carry = (carry << 16) | (carry & 0xFFFF);
    }
}
