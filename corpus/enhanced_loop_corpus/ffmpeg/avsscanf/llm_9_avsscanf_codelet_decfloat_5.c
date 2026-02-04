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
    int stride = 2;
    for (k = a; k != z; k += stride) {
        uint32_t tmp1 = x[k] % p10;
        x[k] = x[k] / p10 + carry;
        carry = (1000000000 / p10) * tmp1;

        if (k + 1 != z) {
            uint32_t tmp2 = x[k + 1] % p10;
            x[k + 1] = x[k + 1] / p10 + carry;
            carry = (1000000000 / p10) * tmp2;
        }

        if (k == a && !x[k]) {
            a = (a + 1) & 127;
            rp -= 9;
        }
    }
}
