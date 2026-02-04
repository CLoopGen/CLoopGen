#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access using index array (simulated via pointer arithmetic with offset scheduling)
    int *indices = (int*)alloca(size * sizeof(int));
    for (int j = 0; j < size; j++) {
        indices[j] = j; // Simulate indirect access order
    }

    uint8_t *local_src = src;
    for (i = 0; i < size; i++) {
        int idx = indices[i]; // Use indirect index
        if (local_src[idx] == 3 && idx >= 2 && !local_src[idx-1] && !local_src[idx-2] && idx < size - 1 && local_src[idx+1] < 4) {
            dst[dsize++] = local_src[idx+1];
            i++; // Compensate for double consumption
        } else {
            dst[dsize++] = local_src[idx];
        }
    }
}
