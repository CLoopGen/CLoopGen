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
    int index = (k * 2) % 128; // Strided access with stride 2, wrapped around buffer size
    uint32_t tmp = x[index] % p10;
    x[index] = x[index] / p10 + carry;
    carry = 1000000000 / p10 * tmp;
    if (k == a && !x[index]) {
        a = (a + 1 & (128 - 1));
        rp -= 9;
    }
}
}
