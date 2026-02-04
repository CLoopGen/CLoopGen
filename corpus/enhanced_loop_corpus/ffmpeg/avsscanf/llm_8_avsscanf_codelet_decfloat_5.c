#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t x[128];
extern int k;
extern int a;
extern int z;
extern int rp;
extern int p10;
extern uint32_t carry;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = a; k != z; k++) {
        uint32_t tmp = x[k] % p10;
        x[k] /= p10;
        carry += (1000000000 / p10) * tmp;
        if (k == a && !x[k]) {
            a = (a + 1) & 127;
            rp -= 9;
        }
    }
}
