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
    int j;
    for (i = 0; i < shuffle_len && in != 0; i++) {
        res |= (in & 1) << *shuffle--;
        in >>= 1;
        // Unroll the loop by processing two iterations per cycle if possible
        if ((i + 1) < shuffle_len && in != 0) {
            i++;
            res |= (in & 1) << *shuffle--;
            in >>= 1;
        }
    }
}
