#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned int uint32;

typedef unsigned short uint16;

extern int32 n_el;
extern uint32 sum;
extern int32 i;
extern uint16 *i16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 local_sum = 0;
    for (i = 0; i < n_el; i += 2) {
        uint32 val1 = (i < n_el) ? i16[i] : 0;
        uint32 val2 = (i + 1 < n_el) ? i16[i + 1] : 0;
        local_sum ^= val1 ^ val2;  // Eliminated cumulative dependency; using XOR to break WAW and WAR
    }
    sum = (sum << 10 | sum >> 22) ^ local_sum;
}
