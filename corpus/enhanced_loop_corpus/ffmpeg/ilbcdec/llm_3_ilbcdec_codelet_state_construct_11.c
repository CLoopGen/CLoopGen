#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t ilbc_state[8];
extern int16_t len;
extern int k;
extern int16_t maxVal;
extern int16_t *tmp1;
extern int16_t *tmp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access on ilbc_state with increasing stride
    // Access ilbc_state with a non-unit stride (e.g., every 2nd element, wrapping if needed)
    // Simulates irregular or strided pattern instead of reverse sequential via tmp2--
    int stride = 2;
    int idx;
    for (k = 0; k < len; k++) {
        idx = (k * stride) & 7;  // Use bitwise AND to wrap within 0-7 (since ilbc_state has size 8)
        (*tmp1) = (int16_t)((((int32_t)(((int16_t)(maxVal)) * ((int16_t)(ilbc_state[idx])))) + 2097152) >> 22);
        tmp1++;
    }
}
