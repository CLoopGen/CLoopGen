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
    x[k] = x[k] / p10 + carry;
    carry = 1000000000 / p10 * tmp;
    int update_condition = (k == a) & (!x[k]);
    if (update_condition) {
        a = (a + 1 & (128 - 1));
        rp -= 9;
    }
}
}
