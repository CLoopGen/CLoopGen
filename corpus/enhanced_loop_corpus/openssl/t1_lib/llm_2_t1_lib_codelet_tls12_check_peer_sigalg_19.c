#include <stdio.h>

#include <inttypes.h>

extern uint16_t sig;
extern  uint16_t *sent_sigs;
extern size_t sent_sigslen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    // This variant accesses every second element in the sent_sigs array.
    // If the array length is odd, we ensure we don't overrun by adjusting loop condition.
    size_t stride = 2;
    size_t effective_len = (sent_sigslen + stride - 1) / stride; // Ceiling division
    uint16_t *ptr = sent_sigs;
    for (i = 0; i < effective_len; i++, ptr += stride) {
        if (sig == *ptr)
            break;
    }
}
