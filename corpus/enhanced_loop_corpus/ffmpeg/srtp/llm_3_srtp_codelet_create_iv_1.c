#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *iv;
extern  uint8_t *salt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate non-sequential access
    const int indices[14] = {0, 2, 4, 6, 8, 10, 12, 1, 3, 5, 7, 9, 11, 13};
    for (i = 0; i < 14; i++) {
        int idx = indices[i];
        iv[idx] ^= salt[idx];
    }
}
