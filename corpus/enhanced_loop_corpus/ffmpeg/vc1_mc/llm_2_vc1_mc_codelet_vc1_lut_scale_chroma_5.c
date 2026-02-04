#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *srcU;
extern uint8_t *srcV;
extern uint8_t *lut1;
extern uint8_t *lut2;
extern int k;
extern int uvlinesize;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 iterations
    uint8_t *sU = srcU;
    uint8_t *sV = srcV;
    for (j = 0; j < k; j += 2) {
        uint8_t *u_ptr = sU;
        uint8_t *v_ptr = sV;
        for (i = 0; i < k; i++) {
            u_ptr[i] = lut1[u_ptr[i]];
            v_ptr[i] = lut1[v_ptr[i]];
        }
        sU += uvlinesize;
        sV += uvlinesize;
        if (j + 1 == k)
            break;
        u_ptr = sU;
        v_ptr = sV;
        for (i = 0; i < k; i++) {
            u_ptr[i] = lut2[u_ptr[i]];
            v_ptr[i] = lut2[v_ptr[i]];
        }
        sU += uvlinesize;
        sV += uvlinesize;
    }
}
