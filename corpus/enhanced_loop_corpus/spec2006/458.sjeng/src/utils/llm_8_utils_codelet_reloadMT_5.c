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
    for (pM = state, j = (397 * 2); --j; s0 = s1, s1 = *p2++) {
        unsigned int y = *pM++ ^ ((((s0) & 2147483648U) | ((s1) & 2147483647U)) >> 1);
        y ^= ((s1) & 1U) ? (2567483615U) : 0U;
        y ^= (y << 7) & 2636928640U; // Additional transformation to increase computational load
        *p0++ = y;
    }
}
