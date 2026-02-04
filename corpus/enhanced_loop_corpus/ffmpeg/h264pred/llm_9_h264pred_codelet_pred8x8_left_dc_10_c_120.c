#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc2;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        int temp1 = src[-1 + i * stride];
        int temp2 = src[-1 + (i + 1) * stride];
        int temp3 = src[-1 + (i + 4) * stride];
        int temp4 = src[-1 + (i + 5) * stride];
        dc0 += temp1 + temp2;
        dc2 += temp3 + temp4;
        dc0 -= (temp1 > temp2) ? temp2 : temp1;
        dc2 -= (temp3 > temp4) ? temp4 : temp3;
    }
}
