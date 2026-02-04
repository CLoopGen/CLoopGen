#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t c;
extern uint64_t n[59];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 58; i > 0; --i) {
        if ((i & 1) == 0) {
            uint64_t nc = ((c + n[i]) >> 1);
            n[i] = c;
            c = nc;
        } else {
            uint64_t temp = c;
            c = n[i];
            n[i] = temp;
        }
    }
}
