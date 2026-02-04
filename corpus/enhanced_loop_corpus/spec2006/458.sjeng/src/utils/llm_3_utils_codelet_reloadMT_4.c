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
    // Variant 2: Strided memory access with step size of 2 (unrolled-like pattern)
    // Access state with stride 2, alternating between even and odd indices where possible
    unsigned int *pM_local = pM;
    unsigned int *p2_local = p2;
    unsigned int s0_local, s1_local;

    // Initialize base values
    s0_local = state[0];
    s1_local = state[2];  // Stride by 2
    int limit = (624 - 397 + 1) / 2;  // Adjust loop count due to striding

    for (j = limit; --j; ) {
        s0_local = s1_local;
        s1_local = (p2_local + 2 <= pM_local + 624) ? *(p2_local += 2) : *(p2_local = (unsigned int*)&state[1]), p2_local++;  // Simulate wrap-around if needed

        *p0++ = *pM_local++ ^ ((((s0_local) & 2147483648U) | ((s1_local) & 2147483647U)) >> 1) ^ (((s1_local) & 1U) ? 2567483615U : 0U);
        // Process next element in stride
        if (j > 1) {
            *p0++ = *pM_local++ ^ ((((s0_local) & 2147483648U) | ((s1_local) & 2147483647U)) >> 1) ^ (((s1_local) & 1U) ? 2567483615U : 0U);
            --j;
        }
    }
}
