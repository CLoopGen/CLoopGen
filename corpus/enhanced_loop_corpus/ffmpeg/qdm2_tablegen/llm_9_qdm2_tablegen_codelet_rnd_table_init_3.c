#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t random_dequant_type24[128][3];
extern int i;
extern int j;
extern uint32_t ldw;
extern uint64_t random_seed;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 128; i += 4) {
    uint64_t seeds[4] = {25, 25, 25, 25};
    uint32_t ldws[4] = {i, i+1, i+2, i+3};
    for (j = 0; j < 3; j++) {
        for (int k = 0; k < 4 && i + k < 128; k++) {
            random_dequant_type24[i + k][j] = ldws[k] / seeds[k];
            ldws[k] %= seeds[k];
            seeds[k] /= 5;
        }
    }
}
}
