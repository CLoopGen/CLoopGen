#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned int uint32;

extern int32 n_el;
extern uint32 sum;
extern int32 i;
extern uint32 *i32;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_el * 3; i++) {
        uint32 idx = i % n_el;
        sum = (sum << 21 | sum >> 11) + i32[idx] + (i32[idx] >> 8) - (i32[idx] << 3);
    }
}
