#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t c;
extern uint64_t a0;
extern uint64_t a1;
extern uint64_t t1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 63; i >= 0; i--) {
    uint64_t bit = (a0 >> i) & 1;
    a1 = a1 + a1 + bit;
    t1 = t1 + t1;
    int64_t temp_c = c;
    if (temp_c <= a1) {
        a1 -= temp_c;
        t1 += 1;
    }
}
}
