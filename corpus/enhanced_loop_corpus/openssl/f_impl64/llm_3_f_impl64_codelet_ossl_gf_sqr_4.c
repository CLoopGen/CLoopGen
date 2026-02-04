#include <stdio.h>

#include <inttypes.h>

extern  uint64_t *a;
extern uint64_t aa[4];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using fixed index mapping (reverse access pattern)
    unsigned int indices[4] = {3, 2, 1, 0};
    for (i = 0; i < 4; i++) {
        unsigned int idx = indices[i];
        aa[idx] = a[idx] + a[idx + 4];
    }
}
