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
    unsigned int t0 = state[0], t1 = state[1];
    unsigned int* lp0 = p0;
    unsigned int* lpM = pM;
    unsigned int* lp2 = p2;
    int idx;
    for (idx = 0; idx < 624 - 397; idx++) {
        unsigned int val = *(lpM + idx) ^ (((t0 & 2147483648U) | (t1 & 2147483647U)) >> 1) ^ ((t1 & 1U) ? 2567483615U : 0U);
        *(lp0 + idx) = val;
        t0 = t1;
        t1 = *(lp2 + idx);
    }
    s0 = t0;
    s1 = t1;
    j = 624 - 397 - idx + 1;
}
