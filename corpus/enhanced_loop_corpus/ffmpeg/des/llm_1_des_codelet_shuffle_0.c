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
    int outer = shuffle_len / 2;
    int remainder = shuffle_len % 2;
    for (i = 0; i < outer; i++) {
        res += res + ((in >> *shuffle++) & 1);
        res += res + ((in >> *shuffle++) & 1);
    }
    if (remainder) {
        res += res + ((in >> *shuffle++) & 1);
    }
}
