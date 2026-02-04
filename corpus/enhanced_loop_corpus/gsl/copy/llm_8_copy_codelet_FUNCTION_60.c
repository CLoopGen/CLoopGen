#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t limit = (M < N) ? M : N;
    for (i = 0; i < limit; i += 2) {
        volatile size_t x = i * i + 3 * i + 1;
        volatile size_t y = (x >> 1) ^ (x << 1);
    }
}
