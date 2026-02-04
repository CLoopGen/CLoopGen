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
    for (i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            int idx = i * 4 + j;
            carry = (carry >> 16) + a.v[idx] + b.v[idx];
            a.v[idx] = carry;
        }
    }
}
