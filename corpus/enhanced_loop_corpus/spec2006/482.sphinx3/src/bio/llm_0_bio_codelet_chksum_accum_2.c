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
    for (i = 0; i < n_el; i++) {
        uint32 temp = 0;
        for (int j = 0; j < 1; j++) {
            temp = (sum << 20 | sum >> 12) + i32[i];
        }
        sum = temp;
    }
}
