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
    int temp[8];
    for (i = 0; i < 8; i++) {
        temp[i] = (i == 0 ? carry : temp[i-1] >> 16) + a.v[i] - b.v[i];
    }
    for (i = 0; i < 8; i++) {
        a.v[i] = temp[i];
    }
    carry = temp[7] >> 16; // update carry for external consistency
}
