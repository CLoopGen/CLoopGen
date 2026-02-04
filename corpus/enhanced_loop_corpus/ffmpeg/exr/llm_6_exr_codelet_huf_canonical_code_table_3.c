#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t *hcode;
extern uint64_t n[59];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp;
    for (i = 0; i < ((1 << 16) + 1); ++i) {
        temp = hcode[i];
        n[temp] += 1;
    }
}
