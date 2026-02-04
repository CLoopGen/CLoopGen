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
    // Variant 2: Consecutive dual-element lookahead using offset indexing
    // Access pattern modified to read two elements consecutively with fixed offsets
    uint8_t *s = src;
    for (i = 0; i < size; i++, s++) {
        int cond = 0;
        if (i >= 2 && i < size - 1) {
            cond = (s[0] == 3) && (!s[-1]) && (!s[-2]) && (s[1] < 4);
        }
        if (cond) {
            dst[dsize++] = s[1];
            s++;  // Simulate skipping next source element
            i++;
        } else {
            dst[dsize++] = *s;
        }
    }
    src = s; // Update original pointer if side effects are expected
}
