#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t *hcode;
extern uint64_t n[59];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 2; ++j)
        for (i = 0; i < ((1 << 16) + 1); ++i)
            n[hcode[i]] += 1;
}
