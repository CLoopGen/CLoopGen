#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        int temp0 = src[i * 2 - stride];
        int temp1 = src[i * 2 + 1 - stride];
        int temp2 = src[i * 2 + 4 - stride];
        int temp3 = src[i * 2 + 5 - stride];
        dc0 += temp0 + temp1;
        dc1 += temp2 + temp3;
        dc0 += (temp0 & temp1);
        dc1 += (temp2 | temp3);
    }
}
