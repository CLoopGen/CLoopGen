#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp = 0;
    for (i = 0; i < ((M) < (N) ? (M) : (N)); i++) {
        temp += i * 2;
    }
    // Introduce a write-after-write (WAW) dependency on temp, but no loop-carried dependency since temp is reused.
    temp = temp > 0 ? temp : 1;
}
