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
        uint32_t temp1 = (uint32_t)a.v[i] + (carry & 0xFFFF);
        uint32_t temp2 = (uint32_t)b.v[i] + (carry >> 16);
        carry = temp1 - temp2;
        a.v[i] = (uint16_t)(carry & 0xFFFF);
    }
}
