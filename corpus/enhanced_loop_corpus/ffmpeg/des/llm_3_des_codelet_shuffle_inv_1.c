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
    for (i = 0; i < shuffle_len; i += 2) {
        if (i + 1 < shuffle_len) {
            res |= (in & 1) << shuffle[i];
            in >>= 1;
            res |= (in & 1) << shuffle[i + 1];
            in >>= 1;
        } else {
            res |= (in & 1) << shuffle[i];
            in >>= 1;
        }
    }
}
