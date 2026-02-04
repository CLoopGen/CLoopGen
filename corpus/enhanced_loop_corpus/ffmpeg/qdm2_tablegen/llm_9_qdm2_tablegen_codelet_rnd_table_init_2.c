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
for (i = 0; i < 256; i++) {
    random_seed = 243;
    ldw = i ^ 17;
    for (j = 0; j < 7; j++) {
        if (j % 2 == 0) {
            random_dequant_index[i][j/2] = (ldw + random_seed) / 5;
        } else {
            uint64_t temp = (ldw * 7) ^ random_seed;
            random_dequant_index[i][j/2] ^= temp % 255;
        }
        ldw = (ldw * 1103515245 + 12345) & 0xFFFF;
        random_seed = (random_seed * 69069) & 0xFFFFFFFF;
    }
}
}
