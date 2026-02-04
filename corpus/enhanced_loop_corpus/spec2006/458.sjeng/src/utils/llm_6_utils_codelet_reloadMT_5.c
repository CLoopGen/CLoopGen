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
    unsigned int temp;
    for (pM = state, j = 397; --j; s0 = s1, s1 = *p2++) {
        temp = ((((s0) & 2147483648U) | ((s1) & 2147483647U)) >> 1);
        temp ^= (((s1) & 1U) ? 2567483615U : 0U);
        *p0++ = *pM++ ^ temp;
    }
}
