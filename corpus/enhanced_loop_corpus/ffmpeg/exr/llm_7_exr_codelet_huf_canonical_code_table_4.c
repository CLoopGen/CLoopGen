#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t c;
extern uint64_t n[59];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t prev_c = c;
    for (i = 58; i > 0; --i) {
        uint64_t nc = ((prev_c + n[i]) >> 1);
        n[i] = prev_c;
        prev_c = nc;
    }
    c = prev_c;
}
