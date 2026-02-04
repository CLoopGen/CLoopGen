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
for (i = 31; i >= 0; i -= 2) {
    a1 += a1;
    a1 += ((a0 >> i) & 1);
    a1 += ((a0 >> (i-1)) & 1); // process two bits per iteration
    t1 += t1;
    t1 += t1;
    if (c <= a1) {
        a1 -= c;
        t1++;
    }
}
}
