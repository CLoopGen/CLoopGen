#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t a;
extern uint64_t b;
extern uint64_t r;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t indices[4] = {0, 2, 1, 3}; // indirect access pattern
    uint64_t temp_a[4], temp_b[4];
    for (int j = 0; j < 4; j++) {
        temp_a[j] = a << (j * 8);
        temp_b[j] = b + (j * 100);
    }
    r = 0;
    for (i = 0; i < 4; i++) {
        int idx = indices[i]; // indirect access
        temp_a[idx] <<= 16;
        r = (r << 16) | (temp_a[idx] / temp_b[idx]);
        temp_a[idx] %= temp_b[idx];
    }
    a = temp_a[0];
}
