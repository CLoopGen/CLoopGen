#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *bits;
extern unsigned int num;
extern unsigned int i;
extern unsigned int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int local_num = num;
    unsigned int idx = p;
    for (; (idx < local_num) && (bits[idx] == 0); ++idx)
        ;
    i = idx;
}
