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
    // Variant 2: Indirect Access via Index Array (simulated using alternating pattern)
    int idx;
    for (i = 0; i < size; i++) {
        idx = (i % 2 == 0) ? i : (i + size / 4) % size;  // Simulate non-consecutive indirect access pattern
        uint8_t* s = &src[idx];

        if (s[0] == 3 && idx >= 2 && idx < size - 1 && !src[idx - 1] && !src[idx - 2] && src[idx + 1] < 4) {
            dst[dsize++] = src[idx + 1];
            i++;  // Compensate by skipping next logical iteration
        } else {
            dst[dsize++] = src[idx];
        }
    }
}
