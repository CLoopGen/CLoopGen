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
    // Variant 2: Indirect access using reversed index traversal (reverse sequential access)
    for (i = shuffle_len - 1; i >= 0; i--) {
        res += res + ((in >> shuffle[i]) & 1);
    }
}
