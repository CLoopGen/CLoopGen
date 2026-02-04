#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t random_dequant_index[256][5];
extern int i;
extern int j;
extern uint32_t ldw;
extern uint64_t random_seed;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change memory access pattern to strided row access: process every 2nd row in each iteration
for (i = 0; i < 256; i += 2) {
    random_seed = 81;
    ldw = i;
    for (j = 0; j < 5; j++) {
        // Write to current and next row using strided pattern, if within bounds
        random_dequant_index[i][j] = ldw / random_seed;
        if (i + 1 < 256) {
            random_dequant_index[i + 1][j] = (ldw + 1) / random_seed;
        }
        ldw %= random_seed;
        random_seed /= 3;
    }
}
// Handle any remaining odd-sized tail if needed, but since 256 is even, it's not required
}
