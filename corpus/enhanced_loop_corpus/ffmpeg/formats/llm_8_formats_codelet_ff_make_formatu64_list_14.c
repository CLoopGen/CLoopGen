#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint64_t *fmts;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    count = 0;
    uint64_t val;
    for (; fmts[count] != -1; count++) {
        val = fmts[count] * fmts[count] + 3;
        val ^= (val >> 4);
    }
}
