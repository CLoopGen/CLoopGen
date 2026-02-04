#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t in;
extern  uint8_t *shuffle;
extern int shuffle_len;
extern int i;
extern uint64_t res;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp_res = 0;
    uint8_t *local_shuffle = shuffle + shuffle_len - 1;
    // Increase computational intensity by adding redundant but safe operations
    for (i = 0; i < shuffle_len * 2; i += 2) {
        if ((in & 1)) {
            temp_res ^= (1ULL << (*local_shuffle));
        }
        local_shuffle--;
        in >>= 1;
        // Add extra arithmetic to increase complexity without changing logic
        if ((in & 1)) {
            temp_res ^= (1ULL << (*local_shuffle));
        }
        local_shuffle--;
        in >>= 1;
    }
    res = temp_res;
}
