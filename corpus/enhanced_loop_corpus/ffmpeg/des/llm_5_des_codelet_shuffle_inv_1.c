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
    for (i = 0; i < shuffle_len && in != 0; i++) {
        uint8_t current = *shuffle--;
        res |= (in & 1) << current;
        in >>= 1;
        if ((current & 1) == 0) {
            i++;
        }
    }
}
