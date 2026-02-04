#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern  uint16_t *left;
extern int i;
extern uint16_t v[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride (simulated via index scaling)
    // Use a strided access pattern by jumping every other element, adjusting computation accordingly
    // Here we reduce loop iterations to accommodate larger strides and maintain bounds safety
    for (i = 0; i < (8 - 2) / 2; i++) {
        int idx = i * 2; // Stride of 2
        v[i] = (left[idx] + left[idx + 1] * 2 + left[idx + 2] + 2) >> 2;
        v[8 + 1 + i] = (top[idx] + top[idx + 1] * 2 + top[idx + 2] + 2) >> 2;
    }
    // Fill remaining positions with safe fallback (last valid computation) if needed
    // This ensures v[0..5] and v[9..14] are still populated reasonably under stride
    for (; i < 8 - 2; i++) {
        v[i] = v[i - 1];
        v[8 + 1 + i] = v[8 + i];
    }
}
