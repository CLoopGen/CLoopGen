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
    for (i = 0; i < 4; i += 2) {
        carry = (carry >> 16) + a.v[i] + b.v[i];
        a.v[i] = carry;
        if (i + 1 < 8) {
            carry = (carry >> 16) + a.v[i+1] + b.v[i+1];
            a.v[i+1] = carry;
        }
    }
}
