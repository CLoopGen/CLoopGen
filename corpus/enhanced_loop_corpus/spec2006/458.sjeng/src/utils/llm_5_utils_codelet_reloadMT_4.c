#include <stdio.h>

#include <inttypes.h>

extern unsigned int state[625];
extern unsigned int *p0;
extern unsigned int *p2;
extern unsigned int *pM;
extern unsigned int s0;
extern unsigned int s1;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (s0 = state[0], s1 = state[1], j = (624) - (397) + 1; --j; s0 = s1, s1 = *p2++) {
        unsigned int temp = *pM++ ^ ((((s0) & 2147483648U) | ((s1) & 2147483647U)) >> 1);
        if ((s1 & 1U) == 0) {
            *p0++ = temp;
            continue;
        }
        *p0++ = temp ^ 2567483615U;
    }
}
