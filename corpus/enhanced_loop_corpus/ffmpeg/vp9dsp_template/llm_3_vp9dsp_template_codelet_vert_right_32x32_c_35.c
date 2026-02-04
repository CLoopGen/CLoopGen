#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t ve[47];
extern uint8_t vo[47];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32 - 1; i++) {
    int offset = 32 / 2 + i;
    // Consecutive write pattern using reversed read order
    int read_idx = 31 - i; // Reverse traversal of top array
    if (read_idx >= 1 && read_idx + 1 < 47) {
        ve[offset] = (top[read_idx] + top[read_idx + 1] + 1) >> 1;
        vo[offset] = (top[read_idx - 1] + top[read_idx] * 2 + top[read_idx + 1] + 2) >> 2;
    }
}
}
