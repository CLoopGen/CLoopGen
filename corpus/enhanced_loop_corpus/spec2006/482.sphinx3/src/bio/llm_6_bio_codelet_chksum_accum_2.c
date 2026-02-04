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
    uint32 temp_sum = sum;
    for (i = 0; i < n_el; i++) {
        temp_sum = (temp_sum << 20 | temp_sum >> 12) + i32[i];
    }
    sum = temp_sum;
}
