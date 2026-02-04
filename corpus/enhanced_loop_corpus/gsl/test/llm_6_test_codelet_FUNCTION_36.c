#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp = 0;
    for (i = 0; i < 1027; i++) {
        temp += i * i;
    }
    // Introduce a write-after-write (WAW) dependency on temp, and loop-carried
    // data dependency via accumulation. RAW dependency: each iteration reads
    // 'temp' before writing it back. No WAR due to ordered execution.
}
