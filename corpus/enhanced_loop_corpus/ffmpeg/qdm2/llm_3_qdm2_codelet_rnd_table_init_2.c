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
for (j = 0; j < 3; j++) {
    for (i = 0; i < 128; i++) {
        uint64_t temp_seed = 25;
        uint32_t temp_lw = i;
        for (int k = 0; k < j; k++) {
            temp_lw %= temp_seed;
            temp_seed /= 5;
        }
        random_dequant_type24[i][j] = temp_lw / temp_seed;
    }
}
}
