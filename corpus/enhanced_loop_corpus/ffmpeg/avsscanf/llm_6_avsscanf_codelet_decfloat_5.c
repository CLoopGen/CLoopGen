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
        uint32_t temp_val = x[k];
        uint32_t tmp = temp_val % p10;
        carry = 1000000000 / p10 * tmp;
        x[k] = temp_val / p10 + carry;
        if (k == a && !(temp_val / p10 + carry)) {
            a = (a + 1) & (128 - 1);
            rp -= 9;
        }
    }
}
