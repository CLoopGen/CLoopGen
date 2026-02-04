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
    uint16_t local_v[8];
    int local_carry = carry;
    for (i = 0; i < 8; i++) {
        local_carry = (local_carry >> 16) + a.v[i] + b.v[i];
        local_v[i] = local_carry;
    }
    for (i = 0; i < 8; i++) {
        a.v[i] = local_v[i];
    }
    carry = local_carry;
}
