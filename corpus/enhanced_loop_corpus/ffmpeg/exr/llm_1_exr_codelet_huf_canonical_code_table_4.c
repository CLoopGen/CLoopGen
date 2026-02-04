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
    uint64_t nc = ((c + n[i]) >> 1);
    n[i] = c;
    c = nc;
    if (i == 29) {
        for (int k = 58; k > 0; --k) {
            uint64_t temp = ((c + n[k]) >> 1);
            n[k] = c;
            c = temp;
        }
    }
}
}
