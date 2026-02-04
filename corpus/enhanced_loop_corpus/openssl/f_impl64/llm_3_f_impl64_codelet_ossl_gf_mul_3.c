#include <stdio.h>

#include <inttypes.h>

extern  uint64_t *a;
extern  uint64_t *b;
extern uint64_t aa[4];
extern uint64_t bb[4];
extern uint64_t bbb[4];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive and Reordered Memory Access Pattern
    // Reorder memory operations to group consecutive accesses to same arrays
    // to improve spatial locality and potential cache utilization.

    // First, compute all 'aa' values with consecutive reads from 'a'
    for (i = 0; i < 4; i++) {
        aa[i] = a[i] + a[i + 4];
    }

    // Then, compute 'bb' and 'bbb' together, reusing 'b' with consecutive access
    for (i = 0; i < 4; i++) {
        bb[i] = b[i] + b[i + 4];
    }
    for (i = 0; i < 4; i++) {
        bbb[i] = bb[i] + b[i + 4];
    }
}
