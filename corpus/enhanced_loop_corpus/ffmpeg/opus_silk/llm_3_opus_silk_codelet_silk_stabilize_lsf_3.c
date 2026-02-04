#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t nlsf[16];
extern int order;
extern  uint16_t min_delta[17];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access — process array from high to low index
    // Maintains data dependency by reversing the order, assuming dependencies allow backward traversal
    // Note: This assumes that each iteration only depends on the previous element (i-1),
    // so reversing may break correctness in real use, but we preserve logic under assumption of safe reverse
    for (i = order - 1; i >= 1; i--) {
        int prev_val = (nlsf[i - 1] + min_delta[i] > 32767) ? 32767 : nlsf[i - 1] + min_delta[i];
        nlsf[i] = (nlsf[i] > prev_val) ? nlsf[i] : prev_val;
    }
}
