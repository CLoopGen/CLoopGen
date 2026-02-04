#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t x[128];
extern  uint32_t th[];
extern int i;
extern int k;
extern int a;
extern int z;
extern int rp;
extern int e2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t carry = 0;
    int sh = 1;
    i = 0;
    for (; i < 2; ++i) {
        k = (a + i) & 127;
        if (x[k] >= th[i]) {
            if (x[k] > th[i]) break;
        } else {
            i = 2;
            break;
        }
    }
    if (i != 2 || rp <= 27) {
        if (rp > 27) sh = 9;
        e2 += sh;
        k = a;
        for (; k != z; k = (k + 1) & 127) {
            uint32_t tmp = x[k] & ((1 << sh) - 1);
            carry = (1000000000 >> sh) * tmp + carry;
            x[k] = (x[k] >> sh);
            if (k == a && !x[k]) {
                a = (a + 1) & 127;
                i--;
                rp -= 9;
            }
        }
        if (carry) {
            if ((z + 1) % 128 != a) {
                x[z] = carry;
                z = (z + 1) & 127;
            } else {
                x[(z - 1) & 127] |= 1;
            }
        }
    }
}
