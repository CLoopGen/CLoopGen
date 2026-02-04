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
    unsigned int local_s0, local_s1;
    unsigned int *local_p0 = p0;
    unsigned int *local_pM = state;
    unsigned int *local_p2 = p2 + 1; // Adjust pointer to align access

    for (j = 397; --j;) {
        local_s0 = *(local_pM - 1); // Break dependency by reading earlier value
        local_s1 = *local_p2++;
        *local_p0++ = *local_pM++ ^ ((((local_s0) & 2147483648U) | ((local_s1) & 2147483647U)) >> 1) ^ 
                      (((local_s1) & 1U) ? 2567483615U : 0U);
    }
    p0 = local_p0; // Update global pointer after loop
}
