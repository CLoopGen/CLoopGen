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
    // Variant 1: Consecutive memory access with reversed traversal
    // Instead of forward incrementing pM and p2, traverse state array backwards in fixed strides
    unsigned int temp_state[624];
    unsigned int *p_temp = temp_state;
    for (s0 = state[623], s1 = state[622], j = 624 - 397 + 1; --j; s0 = s1, s1 = state[(623 - (p_temp - temp_state)) - 1], p_temp++)
        *p_temp = state[(623 - (p_temp - temp_state))] ^ ((((s0) & 2147483648U) | ((s1) & 2147483647U)) >> 1) ^ (((s1) & 1U) ? 2567483615U : 0U);
    
    // Copy result back to original output via p0
    for (int i = 0; i < 624 - 397; ++i)
        p0[i] = temp_state[i];
}
