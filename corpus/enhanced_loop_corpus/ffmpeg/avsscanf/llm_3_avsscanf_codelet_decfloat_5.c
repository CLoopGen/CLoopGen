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
int indices[128];
for (int i = 0; i < 128; i++) {
    indices[i] = (a + i) & (128 - 1); // Precomputed indirect access order
}
for (k = a; k != z; k++) {
    int pos = k & (128 - 1);
    int index = indices[pos]; // Indirect access via lookup table
    uint32_t tmp = x[index] % p10;
    x[index] = x[index] / p10 + carry;
    carry = 1000000000 / p10 * tmp;
    if (k == a && !x[index]) {
        a = (a + 1 & (128 - 1));
        rp -= 9;
    }
}
}
