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
    for (i = 0; i < 384; i++) { // Flattened the 2D logic into a single loop
        int outer_i = i / 3;
        int j = i % 3;
        if (outer_i < 128) {
            if (j == 0) {
                random_seed = 25;
                ldw = outer_i;
            }
            random_dequant_type24[outer_i][j] = ldw / random_seed;
            ldw %= random_seed;
            random_seed /= 5;
        }
    }
}
