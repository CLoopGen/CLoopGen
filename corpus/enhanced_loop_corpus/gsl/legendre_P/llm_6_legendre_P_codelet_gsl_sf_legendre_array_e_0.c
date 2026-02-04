#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t nlm;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp = 0;
    for (i = 0; i < nlm; ++i) {
        temp += i * i;
    }
    // Introduce a write-after-write (WAW) dependency on temp, but no loop-carried dependency since it's reduced after the loop.
    temp = temp > 0 ? temp : 1;
}
