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
    for (pM = state, j = (198); --j; ) {
        s0 = *(pM + 1);
        s1 = p2[j];
        unsigned int mid = ((((s0) & 2147483648U) | ((s1) & 2147483647U)) >> 1);
        if (s1 & 1U)
            mid ^= 2567483615U;
        *p0++ = *pM++ ^ mid;
        *p0++ = *pM++ ^ mid ^ 123456789U; // Double write per iteration, reduced trip count
        s0 = s1;
    }
}
