#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t c;
extern uint64_t n[59];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 58; i > 1; i -= 2) {
        uint64_t nc1 = ((c + n[i]) >> 1);
        uint64_t nc2 = ((c + n[i-1]) >> 1);
        n[i] = c;
        n[i-1] = c;
        c = (nc1 + nc2) >> 1;
    }
}
