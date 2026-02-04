#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE key_buff1[8388608];
extern INT_TYPE i;
extern INT_TYPE prv_buff1[524288];



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via modulo addressing as proxy for indirect)
    INT_TYPE indices[1 << 19];
    for (INT_TYPE j = 0; j < (1 << 19); j++) {
        indices[j] = (j * 5 + 1) % (1 << 19); // generate scrambled but unique-ish indices
    }
    for (i = 0; i < (1 << 19); i++) {
        INT_TYPE idx = indices[i];
        key_buff1[idx] += prv_buff1[idx];
    }
}
