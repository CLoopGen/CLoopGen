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
    random_seed = 25;
    uint32_t temp_ldw[4];
    for (int k = 0; k < 4 && (i + k) < 128; k++) {
        temp_ldw[k] = i + k;
    }
    for (j = 0; j < 3; j++) {
        for (int k = 0; k < 4 && (i + k) < 128; k++) {
            random_dequant_type24[i + k][j] = temp_ldw[k] / random_seed;
            temp_ldw[k] %= random_seed;
        }
        random_seed /= 5;
    }
}
}
