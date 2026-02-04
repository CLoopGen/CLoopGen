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
    for (j = 0; j < shuffle_len; j++) {
        for (i = 0; i < 1; i++)
            res += res + ((in >> *shuffle++) & 1);
    }
}
