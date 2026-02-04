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
    unsigned int local_state[2];
    local_state[0] = state[0];
    local_state[1] = state[1];
    unsigned int* local_p0 = p0;
    unsigned int* local_pM = pM;
    unsigned int* local_p2 = p2;
    int count = 624 - 397 + 1;
    while (--count) {
        unsigned int result = *local_pM ^ (((local_state[0] & 2147483648U) | (local_state[1] & 2147483647U)) >> 1) ^ ((local_state[1] & 1U) ? 2567483615U : 0U);
        *local_p0 = result;
        local_state[0] = local_state[1];
        local_state[1] = *local_p2;
        local_p0++;
        local_pM++;
        local_p2++;
    }
    s0 = local_state[0];
    s1 = local_state[1];
    j = count;
}
