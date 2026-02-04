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
    // Variant 2: Consecutive dual-element access using pointer arithmetic with fixed offset window
    // Accesses are now done via a sliding window of two elements, ensuring coalesced access
    uint8_t *s = src;
    for (i = 0; i < size; i++) {
        if (i >= 2 && i < size - 1 &&
            s[0] == 3 &&
            s[-1] == 0 &&
            s[-2] == 0 &&
            s[1] < 4) {
            dst[dsize++] = s[1];
            s += 2;  // advance pointer by 2
            i++;     // compensate index
        } else {
            dst[dsize++] = *s;
            s++;
        }
    }
    src = s; // update global src pointer after traversal
}
