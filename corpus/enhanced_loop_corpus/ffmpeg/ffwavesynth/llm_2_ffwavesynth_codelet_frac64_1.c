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
    uint64_t arr_a[4] = {a, a << 1, a << 2, a << 3};
    uint64_t arr_b[4] = {b, b + 1, b + 2, b + 3};
    r = 0;
    for (i = 0; i < 4; i++) {
        arr_a[i] <<= 16;
        r = (r << 16) | (arr_a[i] / arr_b[i]);
        arr_a[i] %= arr_b[i];
    }
    a = arr_a[0]; // preserve side effect on a if needed
}
