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
    uint32 local_sum = 0;
    for (i = 0; i < n_el; i += 4) {
        local_sum += i32[i];
        if (i + 1 < n_el) local_sum += i32[i + 1];
        if (i + 2 < n_el) local_sum += i32[i + 2];
        if (i + 3 < n_el) local_sum += i32[i + 3];
    }
    sum = (sum << 20 | sum >> 12) + local_sum;
}
