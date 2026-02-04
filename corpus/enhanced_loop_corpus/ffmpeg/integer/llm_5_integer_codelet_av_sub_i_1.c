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
    for (i = 0; i < 8; ++i) {
        carry = (carry >> 16) + a.v[i] - b.v[i];
        if (carry >= 0) {
            a.v[i] = carry;
        } else {
            a.v[i] = 0;
        }
    }
}
