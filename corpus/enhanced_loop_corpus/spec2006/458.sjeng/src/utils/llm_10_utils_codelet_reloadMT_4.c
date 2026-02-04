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
    unsigned int buffer[624 - 397];
    int n = 624 - 397;
    unsigned int s0_prev = state[0], s1_next = state[1];
    for (int i = 0; i < n; i++) {
        buffer[i] = *(pM + i) ^ (((s0_prev & 2147483648U) | (s1_next & 2147483647U)) >> 1) ^ ((s1_next & 1U) ? 2567483615U : 0U);
        s0_prev = s1_next;
        s1_next = *(p2 + i);
    }
    for (int i = 0; i < n; i++) {
        *p0++ = buffer[i];
    }
    s0 = s0_prev;
    s1 = s1_next;
    j = 1;
}
