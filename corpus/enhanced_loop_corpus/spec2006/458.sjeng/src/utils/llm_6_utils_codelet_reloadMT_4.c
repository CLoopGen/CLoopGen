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
    unsigned int temp_s0 = s0, temp_s1 = s1;
    int local_j = j;
    for (temp_s0 = state[0], temp_s1 = state[1], local_j = 624 - 397 + 1; --local_j; ) {
        unsigned int computed_val = *pM ^ ((((temp_s0) & 2147483648U) | ((temp_s1) & 2147483647U)) >> 1) ^ (((temp_s1) & 1U) ? 2567483615U : 0U);
        *p0 = computed_val;
        p0++;
        pM++;
        temp_s0 = temp_s1;
        temp_s1 = *p2++;
    }
    s0 = temp_s0;
    s1 = temp_s1;
    j = local_j;
}
